#pragma once
#include "Static_Namespace.hpp"
#include "Time_Period.hpp"
#include "Vector_String.hpp"

using static_namespace::typedata;
class TripsTable
{
public:
    //big four
    TripsTable();
    TripsTable(const TripsTable& other);
    TripsTable& operator=(const TripsTable& other);
    ~TripsTable();

    //methods
    void setDestination(const char* destination);
    void setInterval(const TimePeriod& date);
    void setGrade(int grade);
    void setComment(const char* comment);
    void setPhotos(const Vector_String& photos);

    void inputTrip();
    void outputTrip();

    inline char* getDestination()const { return this->destination; }
    inline TimePeriod getInterval()const { return this->interval; }
    inline int getGrade()const { return this->grade; }
    inline char* getComment()const { return this->comment; }
    inline Vector_String getPhotos()const { return this->photos; }

private:
    //helper methods for big 4
    void clear();
    void copy(const TripsTable& other);

    //data
    char* destination; //Burgas, Bulgaria
    TimePeriod interval; //01.01.2020 \n 02.02.2020
    int grade; //1-5
    char* comment; //blq blq.
    Vector_String photos; //.jpeg and .png only - to add check
};