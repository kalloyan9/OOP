#pragma once
#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;
#include "Publication.h"

namespace globals
{
	enum rights
	{
		blocked, //chete postove no ne publikuva
		normal, //mogat da suzdavat publikaciq i da mahat svoq publikaciq, mogat da smenqt prqkora si ako ne e zaet
		moderator, //normal + mogat da premahnat koq i da e publikaciq, blokirai i otblokirat koi da e potrebitel
		admin //moderator + dobavq i premahva potrebiteli, pri premahvane na potrebitel se triq vs mu postove
	};
	static rights BLOCKED = blocked;
	static rights NORMAL = normal;
	static rights MODERATOR = moderator;
	static rights ADMIN = admin;
}

class User
{
public:
	//methods
	User();
	User(const string& name, unsigned years, short stat);
	void setNickName(const string& name);
	void setYears(unsigned years);
	void setStat(short stat);
	string getNickName()const;
	unsigned getYears()const;
	short getStat()const;

	//publications
	void postText(const string& text);
	void postUrl(const string& url, const string& _content);
	void postImage(const string& path);
	const Publication& getPublication(unsigned i)const;


	friend std::ostream& operator<<(std::ostream& os, const User& user);
	friend std::istream& operator>>(std::istream& is, User& user);


private:
	//data
	string nickname;
	unsigned years;
	short stat;
	vector<Publication> publications;
};