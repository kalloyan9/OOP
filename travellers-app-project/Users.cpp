#include <cstring>
#include <cassert>
#include <iostream>
#include <fstream>

#include "Users.hpp"
#include "Static_Namespace.hpp"
//nqmam pravo da izpolzvam namespace globals v toq
using static_namespace::MAX_STR_INPUT;

Users::Users(const char* name, const char* pass, const char* mail)
    :username(new char[strlen(name) + 1])
    , password(new char[strlen(pass) + 1])
    , email(new char[strlen(mail) + 1])
    , travel()
{
    strcpy(this->username, name);
    strcpy(this->password, pass);
    strcpy(this->email, mail);
}


Users::Users(const Users& other)
{
    copy(other);
}


Users& Users::operator=(const Users& other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}


Users::~Users()
{
    clear();
}
//big four


void Users::clear()
{
    delete[] username;
    username = nullptr;

    delete[] password;
    password = nullptr;

    delete[] email;
    email = nullptr;
}


void Users::copy(const Users& other)
{
    this->username = new char[strlen(other.username) + 1];
    strcpy(this->username, other.username);

    this->password = new char[strlen(other.password) + 1];
    strcpy(this->password, other.password);
    
    this->email = new char[strlen(other.email) + 1];
    strcpy(this->email, other.email);
    
    this->travel = other.travel;//via TripsTable::operator=
}
//helper methods


void Users::setUsername(const char* username)
{
    delete[] this->username;
    this->username = new char[strlen(username) + 1];
    strcpy(this->username, username);
}


void Users::setPassword(const char* password)
{
    delete[] this->password;
    this->password = new char[strlen(password) + 1];
    strcpy(this->password, password);
}


void Users::setEmail(const char* email)
{
    delete[] this->email;
    this->email = new char[strlen(email) + 1];
    strcpy(this->email, email);
}


void Users::setTravel(const TripsTable& travel)
{
    this->travel = travel;
}


void Users::inputUPE() //UPE = Username, Password, Email
{
    char inputStr[MAX_STR_INPUT];
    std::cout << "Input username: ";
    std::cin.getline(inputStr, MAX_STR_INPUT);
    this->setUsername(inputStr);

    std::cout << "Input password: ";
    std::cin.getline(inputStr, MAX_STR_INPUT);
    this->setPassword(inputStr);

    std::cout << "Input email: ";
    std::cin.getline(inputStr, MAX_STR_INPUT);
    this->setEmail(inputStr);

}

int Users::searchInData()
{
    char fileName[MAX_STR_INPUT + 4];//+4 = ".db"
    strcpy(fileName, static_namespace::DATA_FILE_NAME);
    strcat(fileName, ".db");
    std::ofstream out(fileName, std::ios::app | std::ios::binary);//podsigurqvam se che ima takuv fail
    out.close();

    std::ifstream in(fileName, std::ios::binary);
    if (!in)
    {
        std::cerr << "Cant open file.\n";
        return false;
    }

    int k;//broq kratnost
    char readUsername[MAX_STR_INPUT];
    char readPassword[MAX_STR_INPUT];
    char readEmail[MAX_STR_INPUT];
    bool checkU;
    bool checkP;
    bool checkE;
    int len;
    while (!in.eof())
    {
        checkU
            = checkP
            = checkE
            = false;
        k = 0;

        in.read((char*)&len, sizeof(len));
        in.read(readUsername, len);
        ++k;
        if (strcmp(readUsername, this->getUsername()) == 0 && k % 4 == 1)
            checkU = true;

        if (in.eof())//munichka zastrahovka
            break;

        in.read((char*)&len, sizeof(len));
        in.read(readPassword, len);
        ++k;
        if (strcmp(readPassword, this->getPassword()) == 0 && k % 4 == 2)
            checkP = true;


        in.read((char*)&len, sizeof(len));
        in.read(readEmail, len);
        ++k;
        if (strcmp(readEmail, this->getEmail()) == 0 && k % 4 == 3)
            checkE = true;


        if (checkU && checkP && checkE)
        {
            in.close();
            return 1;//all right
        }
        else if (checkU)
            return -1;//already exists
    }

    in.close();
    return 0;//doesnt exist such username
}


bool Users::serializeInData()
{
    char fileName[MAX_STR_INPUT + 4];//+4 = ".db"
    strcpy(fileName, static_namespace::DATA_FILE_NAME);
    strcat(fileName, ".db");

    std::ofstream out(fileName, std::ios::app | std::ios::binary);
    if (!out)
    {
        std::cerr << "error opening file.\n";
        return false;
    }

    int len;//writing instrumets
    char str[MAX_STR_INPUT];

    //writing username
    strcpy(str, this->getUsername());
    len = strlen(str) + 1;
    out.write((const char*)&len, sizeof(len));
    out.write((const char*)str, len);
    //

    //writing password
    strcpy(str, this->getPassword());
    len = strlen(str) + 1;
    out.write((const char*)&len, sizeof(len));
    out.write((const char*)str, len);
    //

    //writing email
    strcpy(str, this->getEmail());
    len = strlen(str) + 1;
    out.write((const char*)&len, sizeof(len));
    out.write((const char*)str, len);
    //

    out.close();
    return true;
}


void Users::outputTravel()
{
    this->travel.outputTrip();
}


void Users::inputTravel()
{
    this->travel.inputTrip();
}


bool Users::serialize()
{
    char fileName[MAX_STR_INPUT + 4]; //+4 =  ".db"
    strcpy(fileName, this->getUsername());
    strcat(fileName, ".db");
    share2Friends();
    std::ofstream out(fileName, std::ios::app | std::ios::binary);
    if (!out)
    {
        std::cerr << "Error opening file.\n";
        return false;
    }

    char str[MAX_STR_INPUT];//instruments for writing
    int len;
    int n;

    //write destination
    strcpy(str, this->travel.getDestination());
    len = strlen(str) + 1;
    out.write((const char*)&len, sizeof(len));
    out.write((const char*)str, len);
    //

    //write time period
    strcpy(str, this->travel.getInterval().getFrom());
    len = strlen(str) + 1;
    out.write((const char*)&len, sizeof(len));
    out.write((const char*)str, len);
    strcpy(str, this->travel.getInterval().getTo());
    len = strlen(str) + 1;
    out.write((const char*)&len, sizeof(len));
    out.write((const char*)str, len);
    //

    //write grade
    n = this->travel.getGrade();
    out.write((const char*)&n, sizeof(n));
    //

    //write comment
    strcpy(str, this->travel.getComment());
    len = strlen(str) + 1;
    out.write((const char*)&len, sizeof(len));
    out.write((const char*)str, len);
    //

    //write photos
    n = this->travel.getPhotos().size();
    out.write((const char*)&n, sizeof(n));
    for (int i = 0; i < n; ++i)
    {
        strcpy(str, this->travel.getPhotos().at(i));
        len = strlen(str) + 1;
        out.write((const char*)&len, sizeof(len));
        out.write((const char*)str, len);
    }


    out.close();
    return true;
}


bool Users::deserialize()//+integrated print
{
    char fileName[MAX_STR_INPUT + 4];//+4 = ".db";
    strcpy(fileName, this->getUsername());
    strcat(fileName, ".db");

    std::ifstream in(fileName, std::ios::binary);
    if (!in)
    {
        //        std::cerr<<"error opening file.\n";
        return false;
    }

    char str[MAX_STR_INPUT];//instruments for reading
    int len;
    int n;
    do//reading from file
    {
        //reading destination
        in.read((char*)&len, sizeof(len));
        if (in.eof())
            break;
        in.read(str, len);
        this->travel.setDestination(str);
        //

        //reading time period
        {//suzdavam izkustwen scope za da ne habq pamet za t
            TimePeriod t;
            in.read((char*)&len, sizeof(len));
            in.read(str, len);
            t.setFrom(str);
            in.read((char*)&len, sizeof(len));
            in.read(str, len);
            t.setTo(str);
            this->travel.setInterval(t);
        }
        //


        //reading grade
        in.read((char*)&n, sizeof(n));
        this->travel.setGrade(n);
        //

        //reading comment
        in.read((char*)&len, sizeof(len));
        in.read(str, len);
        this->travel.setComment(str);
        //

//        reading photos
        {
            Vector_String ph;
            in.read((char*)&n, sizeof(n));
            for (int i = 0; i < n; ++i)
            {
                in.read((char*)&len, sizeof(len));
                in.read(str, len);
                ph.push_back(str);
            }
            this->travel.setPhotos(ph);
        }
        //

        //after reading, printing
        this->outputTravel();
    } while (!in.eof());
    in.close();
    return true;
}


bool Users::areFriends(const char* u1, const char* u2)
{
    char fileName[MAX_STR_INPUT + 8];//+8 = "_fr.txt"
    strcpy(fileName, u1);
    strcat(fileName, "_fr.txt");
    char str[MAX_STR_INPUT];
    std::ofstream out(fileName, std::ios::app);//make sure there is file
    out.close();

    std::ifstream in(fileName);
    if (!in)
    {
        std::cerr << "error opening file.\n";
        return false;
    }
    while (!in.eof())
    {
        in >> str;
        if (in.eof())
            break;
        if (strcmp(u2, str) == 0)
        {
            in.close();
            return true;
        }
    }
    in.close();
    return false;
}


bool Users::addFriend(const char* name)
{
    char fileName[MAX_STR_INPUT + 8];//+8 = "_fr.txt"
    strcpy(fileName, this->getUsername());
    strcat(fileName, "_fr.txt");
    char str[MAX_STR_INPUT];

    if (areFriends(this->getUsername(), name))
    {
        std::cerr << "You are already friends. :)\n";
        return false;
    }

    std::ofstream out(fileName, std::ios::app);
    if (!out)
    {
        std::cerr << "error opening file.\n";
        return false;
    }
    out << name << " ";
    out.close();

    strcpy(fileName, name);
    strcat(fileName, "_fr.txt");
    out.open(fileName, std::ios::app);
    if (!out)
    {
        std::cerr << "error opening file.\n";
        return false;
    }
    out << this->getUsername() << " ";
    out.close();
    return true;
}


void Users::seeFriendTrip(const char* fr, const char* dest)
{
    if (!areFriends(this->getUsername(), fr))
    {
        std::cerr << "Sorry but you and " << fr << " are not friends :(\nYou may want to change that.\n";
        return;
    }

    char fileName[MAX_STR_INPUT + 10];//+10 = "_trips.txt"
    strcpy(fileName, fr);
    strcat(fileName, "_trips.txt");
    std::ifstream in(fileName);
    if (!in)
    {
        std::cerr << "Your friend doesn't have any trips in our base :(\n";
        return;
    }
    char destination[MAX_STR_INPUT];
    destination[0] = '\0';
    char comment[MAX_STR_INPUT];
    comment[0] = '\0';
    while (!in.eof())
    {
        in.getline(destination, static_namespace::MAX_STR_INPUT);
        if (in.eof())
        {
            break;
        }
        in.getline(comment, static_namespace::MAX_STR_INPUT);
        if (strcmp(destination, dest) == 0 && comment[0] != '\0')
        {
            std::cout << destination << ": ";
            std::cout << comment << "\n";
            in.close();
            return;
        }
    }
    if (strcmp(destination, dest) != 0)
        std::cerr << "Your friend hasn't been in that destination. :(\n";

    in.close();
}


void Users::share2Friends()
{
    char fileName[MAX_STR_INPUT + 10];//+10 = "_trips.txt"
    strcpy(fileName, this->getUsername());
    strcat(fileName, "_trips.txt");

    std::ofstream out(fileName, std::ios::app);
    if (!out)
    {
        std::cerr << "error opening file.\n";
        return;
    }
    out << this->getTravel().getDestination() << "\n";
    out << this->getTravel().getComment() << "\n";
    out.close();
}