#pragma once
#include <fstream>
const int MAX_UNIQUE_NUM = 1024;

namespace globals
{
	enum typePub
	{
		text,
		image,
		url
	};
	static typePub TEXT = text, IMAGE = image, URL = url;
}


class Publication
{
public:
	Publication(const string& _content, const string& _writer, size_t _typePub);

	void setContent(const string& content);
	void setWriter(const string& writer);
	string getContent()const;
	string getUniqueNum()const;
	string getWriter()const;

	friend std::ostream& operator<<(std::ostream& os, const Publication& publication);

	void serializeText();
	void serializeUrl();
	void serializeImage();

	//virtual void serialize();

private:
	//data
	string content;
	static int totalNum;
	char uniqueNum[MAX_UNIQUE_NUM];
	string writer;
};