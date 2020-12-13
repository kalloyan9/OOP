#include "User.h"
#include "Publication.h"
using namespace globals;

User::User() //default constructor
	: nickname(" ")
	, years(99)
	, stat(0)
	, publications()
{}

User::User(const string& name, unsigned years, short stat)
	: nickname(name)
	, years(years)
	, stat(stat)
	, publications()
{}

void User::setNickName(const string & name)
{
	this->nickname = name;
}

void User::setYears(unsigned years)
{
	this->years = years;
}

void User::setStat(short stat)
{
	this->stat = stat;
}

string User::getNickName() const
{
	return this->nickname;
}

unsigned User::getYears() const
{
	return this->years;
}

short User::getStat() const
{
	return this->stat;
}

void User::postText(const string& text)
{
	publications.push_back(Publication(text, this->nickname, TEXT));
}

void User::postUrl(const string& text, const string& _content)
{
	publications.push_back(Publication(text + " " + _content, this->nickname, URL));
}

void User::postImage(const string& path)
{
	publications.push_back(Publication(path, this->nickname, IMAGE));
}

const Publication& User::getPublication(unsigned i)const
{
	if (i >= 0 && i <= publications.size())
		return publications.at(i);
}


std::ostream& operator<<(std::ostream& os, const User& user)
{
	cout << user.nickname << ", " << user.years << "y, $" << user.stat;
	for (int i = 0; i < user.publications.size(); ++i)
		cout << user.publications.at(i) << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, User& user)
{
	string name;
	std::cout << "username: ";
	std::cin >> name;
	user.setNickName(name);

	unsigned years;
	std::cout << "years: ";
	std::cin >> years;
	user.setYears(years);

	int stat;
	std::cout << "rights: ";
	std::cin >> stat;
	user.setStat(stat);
	
	return is;
}
