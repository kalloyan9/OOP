#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include "Publication.h"
int Publication::totalNum = 7;
#include "Syntax.h"
using namespace globals;

Publication::Publication(const string& _content, const string& _writer, size_t _typePub)
	: content(_content)
	, writer (_writer)
{
	++totalNum;
	//binary transformation for uniqueNum
	int n = totalNum, i;
	for (i = 0; n > 0; i++)
	{
		uniqueNum[i] = (n % 2) + '0';
		n /= 2;
	}
	uniqueNum[i] = '\0';
	if (_typePub == TEXT)
		this->serializeText();
	else if (_typePub == URL)
		this->serializeUrl();
	else if (_typePub == IMAGE)
		this->serializeImage();

}
void Publication::setContent(const string& content)
{
	this->content = content;
}

void Publication::setWriter(const string& writer)
{
	this->writer = writer;
}

string Publication::getContent()const
{
	return this->content;
}

string Publication::getUniqueNum() const
{
	return this->uniqueNum;
}

string Publication::getWriter()const
{
	return this->writer;
}

void Publication::serializeText()
{
	std::ofstream out(this->writer + this->uniqueNum + ".html");
	if (out)
	{
		out << firstLine << endl;
		out << "<p>" << this->content << "</p>" << endl;
		out << lastLine;
	}
	out.close();
}

void Publication::serializeUrl()
{
	std::ofstream out(this->writer + this->uniqueNum + ".html");
	if (out)
	{
		char* url = strtok(&content[0], " ");
		char* _content = strtok(NULL, " ");
		out << firstLine << endl;
		out << "<a href=\"" << url << "\">" << _content << "</a>" << endl;
		out << lastLine;
	}
	out.close();
}

void Publication::serializeImage()
{
	std::ofstream out(this->writer + this->uniqueNum + ".html");
	if (out)
	{
		out << firstLine << endl;
		out << "<img src=\">" << this->content << "\">" << endl;
		out << lastLine;
	}
	out.close();
}

std::ostream& operator<<(std::ostream& os, const Publication& publication)
{
	std::cout << publication.writer << " #" << publication.getUniqueNum() << std::endl
		<< publication.content;
	return os;
}
