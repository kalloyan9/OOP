#include <cstring>
#include <iostream>
#include <fstream>

#include "Static_Namespace.hpp"
#include "Destinations.hpp"

void Destinations::addInfo(const Users& users)//serializing
{
    char fileName[MAX_STR_INPUT + 5];//+5 = ".txt"
    strcpy(fileName, users.getTravel().getDestination());
    strcat(fileName, ".txt");
    std::ofstream out(fileName, std::ios::app);
    if (!out)
    {
        std::cerr << "error opening file.\n";
        return;
    }

    out << users.getUsername() << " ";
    out << users.getTravel().getGrade() << " ";

    out.close();
}


void Destinations::getInfo()//deserialize+printing
{
    avg = 0;
    char fileName[MAX_STR_INPUT + 5];//+5 = ".txt"
    strcpy(fileName, this->name);
    strcat(fileName, ".txt");
    std::ofstream out(fileName, std::ios::app);//make sure file is here 
    out.close();
    std::ifstream in(fileName);
    if (!in)
    {
        std::cerr << "No info for that location\n";
        return;
    }
    std::cout << this->name << ":\n";
    char str[MAX_STR_INPUT];
    int userGrade;
    int n = 0;
    while (!in.eof())
    {
        in >> str;
        if (in.eof())
            break;
        in >> userGrade;
        avg += userGrade;
        ++n;
        std::cout << "\n- -";
        std::cout << str << " gave grade: " << userGrade << std::endl;
    }
    if (n == 0)
    {
        std::cerr << "No info for that location\n";
        in.close();
        return;
    }
    avg /= n;
    std::cout << "THIS PLACE's AVERAGE GRADE IS " << avg << "  :)\n";
    in.close();
}


void Destinations::setName(const char* destName)
{
    strcpy(this->name, destName);
}