#include <cstring>
#include <iostream>

#include "Trips_Table.hpp"
#include "Static_Namespace.hpp"
static const int DEFAULT_GRADE = 0;
static const int EMPTY_LEN = 2;//2 = " \n";
static const char* EMPTY_STR = " ";

TripsTable::TripsTable()
    :destination(new char[EMPTY_LEN])
    , interval()
    , grade(DEFAULT_GRADE)
    , comment(new char[EMPTY_LEN])
    , photos()
{
    strcpy(destination, EMPTY_STR);
    strcpy(comment, EMPTY_STR);
}

TripsTable::TripsTable(const TripsTable& other)
    :destination(new char[strlen(other.destination) + 1])
    , comment(new char[strlen(other.comment) + 1])
    , photos(other.photos)
{
    copy(other);
}


TripsTable& TripsTable::operator=(const TripsTable& other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}


TripsTable::~TripsTable()
{
    clear();
}


void TripsTable::clear()
{
    delete[] destination;
    destination = nullptr;
    delete[] comment;
    comment = nullptr;
}


void TripsTable::copy(const TripsTable& other)
{
    delete[] this->destination;
    this->destination = new char[strlen(other.destination) + 1];
    strcpy(this->destination, other.destination);

    this->interval = other.interval;

    this->grade = other.grade;

    delete[] this->comment;
    this->comment = new char[strlen(other.comment) + 1];
    strcpy(this->comment, other.comment);

    this->photos = other.photos;
}


void TripsTable::setDestination(const char* destination)
{
    delete[] this->destination;
    this->destination = new char[strlen(destination) + 1];
    strcpy(this->destination, destination);
}


void TripsTable::setInterval(const TimePeriod& date)
{
    this->interval.setFrom(date.getFrom());
    this->interval.setTo(date.getTo());
}


void TripsTable::setGrade(int grade)
{
    this->grade = grade;
}


void TripsTable::setComment(const char* comment)
{
    delete[] this->comment;
    this->comment = new char[strlen(comment) + 1];
    strcpy(this->comment, comment);
}


void TripsTable::setPhotos(const Vector_String& photos)
{
    this->photos = photos;
}


using static_namespace::MAX_STR_INPUT;
void TripsTable::outputTrip()
{
    std::cout << "- - - - - - - - - -\n";
    std::cout << "Destination:\n";
    std::cout << this->getDestination() << std::endl;

    std::cout << "- - - - - - - - - -\n";
    std::cout << "Time period:\n";
    std::cout << this->getInterval().getFrom() << "\n" << this->getInterval().getTo() << "\n";

    std::cout << "- - - - - - - - - -\n";
    std::cout << "Your grade:\n" << this->getGrade() << std::endl;

    std::cout << "- - - - - - - - - -\n";
    std::cout << "Your comment:\n";
    std::cout << this->getComment() << std::endl;

    std::cout << "- - - - - - - - - -\n";
    std::cout << "Attached photos:\n";
    int n = this->photos.size();
    for (size_t i = 0; i < n; ++i)
        std::cout << this->photos.at(i) << std::endl;

    //    std::cout<<"- - - - output successful\n";
}



inline bool isCorrect(const char* a)//check for photos name
{
    while (*a)
    {
        if (*a == '\0' || *a == '.')
            break;
        if (!((*a >= 'a' && *a <= 'z') || (*a >= 'A' && *a <= 'Z') || *a == '_'))
            return false;
        ++a;
    }
    return true;
}


void TripsTable::inputTrip()
{
    //destination
    char str[MAX_STR_INPUT];
    std::cout << "- - - - - - - - - -\n";
    std::cout << "Input destination.\n";
    std::cin.getline(str, MAX_STR_INPUT);
    this->setDestination(str);
    //

    //time period
    std::cout << "- - - - - - - - - -\n";
    TimePeriod t;
    do
    {
        std::cout << "Input valid time period (in format DD.MM.YYYY):\n";
        std::cout << "From: ";
        std::cin.getline(str, MAX_STR_INPUT);
        t.setFrom(str);
        std::cout << "To: ";
        std::cin.getline(str, MAX_STR_INPUT);
        t.setTo(str);
    } while (!t.isValid());
    this->setInterval(t);
    //

    //grade
    std::cout << "- - - - - - - - - -\n";
    int g = 0;
    do
    {
        std::cout << "Give a grade(from 1 to 5):\n";
        std::cin >> g;
        std::cin.ignore(MAX_STR_INPUT, '\n');
    } while (!(g >= 1 && g <= 5));
    this->setGrade(g);
    //


    //comment
    std::cout << "- - - - - - - - - -\n";
    std::cout << "Leave a comment for this plase:\n";
    std::cin.getline(str, MAX_STR_INPUT);
    this->setComment(str);
    //

    std::cout << "- - - - - - - - - -\n";
    int n = 0;
    do
    {
        std::cout << "How many photos you may want to attach (minimum 1 photo must be attached): ";
        std::cin >> n;
        std::cin.ignore(MAX_STR_INPUT, '\n');
    } while (n < 1);


    //inputing photos. 
    std::cout << "- - - - - - - - - -\n";
    const char* p = nullptr;
    for (int i = 0; i < n; )//if its ok, ++i, adding exact n photos with correct format
    {
        bool correct = true;
        std::cout << "\nPlease attach photo\n(only .png and .jpeg formats supported. all other data wont be uploaded):\n";
        std::cin.getline(str, MAX_STR_INPUT);
        char check[MAX_STR_INPUT + 1];
        int q = 0;
        correct = isCorrect(str);
        p = str;
        if (correct)
            while (*p)
            {
                while (*p != '.' && *p)//finding the dot
                    ++p;
                while (*p)
                {
                    check[q] = *p;
                    ++p;
                    ++q;
                }
            }
        check[q] = '\0';
        if (correct && (strcmp(check, ".png") == 0 || strcmp(check, ".jpeg") == 0))
        {
            this->photos.push_back(str);//da ne qdem pamet za nov vector
            ++i;
            std::cout << "successfuly attached.\n";
        }
        else
            std::cerr << "unsuported type.\n";
    }
    p = nullptr;
    //    std::cout<<"- - - - input suceed\n";
}