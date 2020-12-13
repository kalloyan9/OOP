#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#define MAX_INPUT 100

class Person
{
private:
        char *name;
        size_t ages;

public:
        Person();
        Person(const Person& other);
        Person(const char* _name, size_t _ages);
        Person& operator=(const Person& other);
        ~Person();
        void copy(const Person& other);
        void clear();

        void setName(const char *_name);
        void setAges(size_t _ages);
        const char* getName() const;
        size_t getAges() const;

        friend std::ostream& operator<<(std::ostream& os, const Person& p);
        friend std::istream& operator>>(std::istream& is, Person& p); 
};

Person::Person()
        : name(new char[1])
        , ages(0)
{
        name[0] = '\0';
}

Person::Person(const Person& other) 
{
        copy(other);
}

Person::Person(const char* _name, size_t _ages) 
{
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        ages = _ages;
}

Person& Person::operator=(const Person& other) 
{
        if(this != &other)
        {
                clear();
                copy(other);
        }
        return *this;
}

Person::~Person() 
{
        clear();
}

void Person::copy(const Person& other) 
{
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->ages = other.ages;
}

void Person::clear() 
{
        delete[] name;
}

void Person::setName(const char *_name) 
{
        delete[] name;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
}

void Person::setAges(size_t _ages) 
{
        ages = _ages;
}

const char* Person::getName() const
{
        return name;
}

size_t Person::getAges() const
{
        return ages;
}

std::istream& operator>>(std::istream& is, Person& p) 
{
        char _name[MAX_INPUT];
        is >> _name;
        p.setName(_name);
        is >> p.ages;

        return is;      
}

std::ostream& operator<<(std::ostream& os, const Person& p) 
{
        os << p.name << " " << p.ages;

        return os;
}

std::string convertToString(const char* a) 
{ 
        std::string s = a; 
        return s; 
} 

int writePerson(const Person& person, const char *FILE)
{
        //writing instruments for binary
        size_t len;
        char str[MAX_INPUT];

        strcpy(str, person.getName());
        len = strlen(str) + 1; // +1 = '\0'
        
        std::ofstream out(FILE, std::ios::binary); // + std::ios::app -> moving ptr to the end (ne trie sudurjanieto)
        if(!out)
                return 1;        
        out.write((const char*)&len, sizeof(len));
        out.write((const char*)str, len);
        len = person.getAges();
        out.write((const char*)&len, sizeof(len));
        out.close();
        return 0;
}

int readPerson(Person& person, const char *FILE)
{
        //writing instruments for binary
        size_t len;
        char str[MAX_INPUT];

        std::ifstream in(FILE, std::ios::binary);
        if(!in)
                return 1;
        in.read((char*)&len, sizeof(len));
        in.read(str, len);
        person.setName(str);
        in.read((char*)&len, sizeof(len));
        person.setAges(len);
        in.close();
        return 0;
}

int main() 
{
        const char *FILE_NAME = "name.db";

        // Person a;
        // std::cin >> a;
        // writePerson(a, FILE_NAME);

        // readPerson(a, FILE_NAME);
        // std::cout << a;
        
        return 0;
}