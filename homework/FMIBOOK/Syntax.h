#pragma once
#include <string>
using std::string;

namespace globals
{
	//HTML
	const string firstLine = "<!DOCTYPE html>\n<html>\n<body>";
	const string lastLine = "</body>\n</html>";
	const string extension = ".html";

	class Syntax
	{
	public:
		//console commands
		const char* quit = "quit";
		//user to user commands
		const char* addModerator = "add_moderator";
		const char* addAdmin = "add_admin";
		const char* addUser = "add_user";
		const char* removeUser = "remove_user";
		const char* blockUser = "block";
		const char* unblockUser = "unblock";
		//
		//user to publication commands
		const char* post = "post";
		const char* image = "[image]";
		const char* url = "[url]";
		const char* text = "[text]";
		const char* view = "view_post";
		const char* removePost = "remove_post";
	};
}
