#include "Globals.hpp"

void globals::simpleInterface::printLogReg()
{
    std::cout << "\n- - - - - - - - - -\n";
    std::cout << "Welcome to traveller's app!\n";
    std::cout << "Please type a command from belowed to continue.\n";
    std::cout << "<reg> to register new user.\n";
    std::cout << "<log> to loggin.\n";
    std::cout << "<exit> to exit.\n";
    std::cout << "PLEASE TYPE A COMMAND:\n";
}

void globals::simpleInterface::printLookAdd()
{
    std::cout << "\n- - - - - - - - - -\n";
    std::cout << "Please type a command from belowed to continue.\n";
    std::cout << "<look> to look your trips.\n";
    std::cout << "<add> to add new trip.\n";
    std::cout << "<vdest> to look destination response.\n";
    std::cout << "<addfr> to add friend.\n";
    std::cout << "<vcomm> to view friend's comment.\n";
    std::cout << "<exit> to exit.\n";
    std::cout << "PLEASE TYPE A COMMAND:\n";
    std::cout << "- - - - - - - - - -\n";
}

int globals::functionality::logRegFunc(Users& user)
{
    globals::cin(command);
    if (strcmp(command, listCommands[0]) == 0)//exit
    {
        return 0;
    }
    else if (strcmp(command, listCommands[1]) == 0)//loggin
    {
        return 1;
    }
    else if (strcmp(command, listCommands[2]) == 0) //register
    {
        return 2;
    }
    else//everything else
    {
        system("clear");
        std::cerr << "invalid command.\n";
        return -1;
    }
}

int globals::functionality::lookAddFunc(Users& user)
{
    globals::cin(command);
    if (strcmp(command, listCommands[0]) == 0)//exit
    {
        return 0;
    }
    else if (strcmp(command, listCommands[3]) == 0) //look
    {
        return 3;
    }
    else if (strcmp(command, listCommands[4]) == 0) //add
    {
        return 4;
    }
    else if (strcmp(command, listCommands[5]) == 0)//destination review
    {
        return 5;
    }
    else if (strcmp(command, listCommands[6]) == 0)//add friend
    {
        return 6;
    }
    else if (strcmp(command, listCommands[7]) == 0)//look friend's comment
    {
        return 7;
    }
    else//everything else
    {
        return -1;
    }
}
