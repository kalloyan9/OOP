#pragma once
//DD.MM.YYYY [11]
const int LEN = 11;

class TimePeriod
{
public:
    //methods
    TimePeriod();
    TimePeriod(const TimePeriod& other);
    TimePeriod& operator=(const TimePeriod& other);

    void setFrom(const char* date);
    void setTo(const char* date);
    inline const char* getFrom()const { return from; }//const for the static array from[LEN]
    inline const char* getTo()const { return to; }
    bool isValid();
private:
    //helpers
    void copy(const TimePeriod& other);

    //data
    char from[LEN];
    char to[LEN];
};