#pragma once
#include "Trips_Table.hpp"
#include "Vector_String.hpp"

class Users
{
public:
    //big four
    Users(const char* name = " ", const char* pass = " ", const char* mail = " ");
    Users(const Users& other);
    Users& operator=(const Users& other);
    ~Users();

    //methods
    void inputUPE();//UPE = username password and email
    int searchInData(); //-1 - username already exists, 0- not such username, 1- username+password+email = users 
                        //po hubavo e s enum
    bool serializeInData();
    void outputTravel();
    void inputTravel();
    bool serialize();//1-succeed, 0-fail
    bool deserialize();//1-succeed, 0-fail(no trips)
    bool addFriend(const char* name);
    bool areFriends(const char* u1, const char* u2);
    void share2Friends();
    void seeFriendTrip(const char* fr, const char* dest);

    //seters
    void setUsername(const char* username);
    void setPassword(const char* password);
    void setEmail(const char* email);
    void setTravel(const TripsTable& travel);

    //getters
    inline char* getUsername()const { return this->username; }
    inline char* getPassword()const { return this->password; }
    inline char* getEmail()const { return this->email; }
    inline TripsTable getTravel()const { return this->travel; }

private:
    //helper methods
    void clear();
    void copy(const Users& other);

    //data
    char* username;
    char* password;
    char* email;
    TripsTable travel;
};