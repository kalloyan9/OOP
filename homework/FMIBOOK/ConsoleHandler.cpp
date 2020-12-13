#include "ConsoleHandler.h"
using namespace globals;

void ConsoleHandler::run()
{
    cout << "Please input admin.\n";
    cout << "nickname: ";
    string a;
    cin >> a;
    cout << "years: ";
    unsigned y;
    cin >> y;
    User admin(a, y, ADMIN);
    //cin >> admin;
    cout << admin << " aded as administrator." << endl;
    cin.ignore(MAX_INPUT_SIZE, '\n');
    users.push_back(admin);
    char cmd[MAX_INPUT_SIZE];
    char* command;
    while (!endProgram)
    {
        cout << "$";
        cin.getline(cmd, MAX_INPUT_SIZE);
        command = strtok(cmd, " ");
        if (!strcmp(command, syntax.quit)) //quit check
        {
            endProgram = true;
            break;
        }
        while (command != NULL) //getting all words to '\0'
        {
            //my commands
            if (!strcmp(command, "countUsers")) //test func
            {
                countUsers();
                break;
            }
            //
            //user commands
            int indexUsername = findUsername(command);
            if (indexUsername != -1)//checking user
            {
                command = strtok(NULL, " ");
                //user to user commands
                if (!strcmp(command, syntax.addUser))
                {
                    if (users.at(indexUsername - 1).getStat() == ADMIN)
                    {
                        command = strtok(NULL, " ");
                        if (findUsername(command) == -1)
                        {
                            char username[MAX_INPUT_SIZE];
                            strcpy(username, command);
                            command = strtok(NULL, " ");
                            unsigned years = atoi(command);
                            users.push_back(User(username, years, NORMAL));
                            cout << username << " added as user.\n";
                        }
                        else
                        {
                            cout << "already exist user " << command << endl;
                            break; //?
                        }
                    }
                    else
                    {
                        cout << users.at(indexUsername - 1).getNickName() << " is not admin.\n";
                        break; //?
                    }
                }
                else if (!strcmp(command, syntax.addModerator))
                {
                    if (users.at(indexUsername - 1).getStat() == ADMIN)
                    {
                        command = strtok(NULL, " ");
                        if (findUsername(command) == -1)
                        {
                            char username[MAX_INPUT_SIZE];
                            strcpy(username, command);
                            command = strtok(NULL, " ");
                            unsigned years = atoi(command);
                            users.push_back(User(username, years, MODERATOR));
                            cout << username << " added as moderator.\n";
                        }
                        else
                        {
                            cout << "already exist user " << command << endl;
                            break; //?
                        }
                    }
                    else
                    {
                        cout << users.at(indexUsername - 1).getNickName() << " is not admin.\n";
                        break; //?
                    }
                }
                else if (!strcmp(command, syntax.addAdmin))
                {
                    if (users.at(indexUsername - 1).getStat() == ADMIN)
                    {
                        command = strtok(NULL, " ");
                        if (findUsername(command) == -1)
                        {
                            char username[MAX_INPUT_SIZE];
                            strcpy(username, command);
                            command = strtok(NULL, " ");
                            unsigned years = atoi(command);
                            users.push_back(User(username, years, ADMIN));
                            cout << username << " added as admin.\n";
                        }
                        else
                        {
                            cout << "already exist user " << command << endl;
                            break; //??
                        }
                    }
                    else
                    {
                        cout << users.at(indexUsername - 1).getNickName() << " is not admin.\n";
                        break; //??
                    }
                }
                else if (!strcmp(command, syntax.removeUser))
                {
                    if (users.at(indexUsername - 1).getStat() == ADMIN)
                    {
                        command = strtok(NULL, " ");
                        int remIdx = findUsername(command);
                        if (remIdx != -1)
                        {
                            users.erase(users.begin() + remIdx - 1);
                            cout << command << " removed.\n";
                            //remove all its publications
                            for (int i = 0; i < publications.size(); ++i)
                            {
                                if (publications.at(i).getWriter() == users.at(indexUsername - 1).getNickName())
                                    publications.erase(publications.begin() + i);
                            }
                        }
                    }
                    else
                        cout << "only admins can do this operation.\n";
                    break;
                }
                //

                //user to publication commands
                //post publication commands
                else if (!strcmp(command, syntax.post))
                {
                    command = strtok(NULL, " ");
                    if (!strcmp(command, syntax.image))
                    {
                        //DONE
                        char* path = strtok(NULL, " ");
                        users.at(indexUsername - 1).postImage(path);
                        cout << "- -posted.\n";
                    }
                    else if (!strcmp(command, syntax.url))
                    {
                        //DONE
                        command = strtok(NULL, " ");
                        char url[globals::MAX_INPUT_SIZE];
                        strcpy(url, command);
                        command = strtok(NULL, " ");
                        users.at(indexUsername - 1).postUrl(url, command);
                        cout << "- -posted.\n";
                    }
                    else if (!strcmp(command, syntax.text))
                    {
                        //DONE
                        char* text = strtok(NULL, " ");
                        users.at(indexUsername - 1).postText(text);
                        cout << "- -posted.\n";
                    }
                    else
                        cout << "unsuported type.\n";
                    break;
                }
                //
                //view publication commands
                else if (!strcmp(command, syntax.view))
                {
                    char* number = strtok(NULL, " ");
                    unsigned num = atoi(number);
                    cout << users.at(indexUsername - 1).getPublication(num) << endl;
                }
                //
                //remove publication commands
                else if (!strcmp(command, syntax.removePost)) //not working properly
                {
                    if (users.at(indexUsername - 1).getStat() == ADMIN
                        || users.at(indexUsername - 1).getStat() == MODERATOR)
                    {
                        command = strtok(NULL, " ");
                        unsigned index = atoi(command);
                        int num = 0;
                        for (int i = 0; i < publications.size(); ++i) //publications.size() = 0 always
                        {
                            if (publications.at(i).getWriter() == users.at(indexUsername - 1).getNickName())
                            {
                                if (num == index)
                                {
                                    //TODO deleting files
                                    publications.erase(publications.begin() + i);
                                    cout << "- -removed.\n";
                                    break;
                                }
                                ++num;
                            }
                        }
                        cout << "invalid post.\n";
                    }
                    else
                        cout << "no moderator rights\n";
                    break;
                }
                //
                //TODO: remembering what rights has the user, and after unblocking giving it the same
                else if (!strcmp(command, syntax.blockUser))
                {
                    if (users.at(indexUsername - 1).getStat() == ADMIN
                        || users.at(indexUsername - 1).getStat() == MODERATOR)
                    {
                        command = strtok(NULL, " ");
                        int indexBlocked = -1;
                        for (int i = 0; i < users.size(); ++i)
                        {
                            if (users.at(i).getNickName() == command)
                            {
                                users.at(i).setStat(BLOCKED);
                                cout << "user " << command << " blocked.\n";
                                break;
                            }
                        }
                        cout << "no such username.\n";
                    }
                    else
                        cout << "no rights to do that.\n";
                    break;
                }
                else if (!strcmp(command, syntax.unblockUser))
                {
                    if (users.at(indexUsername - 1).getStat() == ADMIN
                        || users.at(indexUsername - 1).getStat() == MODERATOR)
                    {
                        command = strtok(NULL, " ");
                        int indexBlocked = -1;
                        for (int i = 0; i < users.size(); ++i)
                        {
                            if (users.at(i).getNickName() == command)
                            {
                                users.at(i).setStat(NORMAL);
                                cout << "user " << command << " unblocked and set as user.\n";
                                break;
                            }
                        }
                        cout << "no such username.\n";
                    }
                    else
                        cout << "no rights to do that.\n";
                    break;
                }
                else
                {
                    cout << "unknown command.\n";
                    break;
                }
            }
            else
            {
                cout << "No such username.\n";
                break;//?
            }
            //
                        
            command = strtok(NULL, " "); //getting next word
        }
    }
    std::cout << "- -bye\n";

}

unsigned ConsoleHandler::countUsers()
{
    int admins = 0
        , moderators = 0
        , normalUsers = 0
        , blockedUsers = 0;
    unsigned i = 0;
    while (i < users.size())
    {
        if (users.at(i).getStat() == BLOCKED)
            ++blockedUsers;
        else if (users.at(i).getStat() == NORMAL)
            ++normalUsers;
        else if (users.at(i).getStat() == MODERATOR)
            ++moderators;
        else if (users.at(i).getStat() == ADMIN)
            ++admins;
        ++i;
    }
    cout << "admins: " << admins
        << ", moderators: " << moderators
        << ", normal users: " << normalUsers
        << ", blocked users: " << blockedUsers;
    cout << endl << "----------" << endl;
    cout << "Total users: " << i << endl;
    return i;
}

int ConsoleHandler::findUsername(const string& name)//returns index + 1, -1 if not found
{
    for (int i = 0; i < users.size(); ++i)
    {
        if (users.at(i).getNickName() == name)
            return i+1;
    }
    return -1;
}
