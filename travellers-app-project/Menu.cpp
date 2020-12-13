#include <iostream>

#include "Globals.hpp"
#include "Menu.hpp"

void Menu::menu1(Users& user)
{
    globals::simpleInterface GSI;//GSI = globals simple interface
    globals::functionality FNC;//FNC = functionality

    int result = 100;
    while (true)
    {
        GSI.printLogReg();
        result = FNC.logRegFunc(user);
        if (result == 0)//exit
        {
            endProgram = true;
            return;
        }
        else if (result == 1)//log
        {
            user.inputUPE();
            if (user.searchInData() == 1)
            {
                //system("cls"); //windows only
                std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                std::cout << "logged successful\n";
                std::cout << "Please press enter to continue";
                std::cin.get();
                return;
            }
            else if (user.searchInData() == -1)
            {
                std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                std::cerr << "Wrong username or password or email.\n";
            }
            else
            {
                std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                std::cerr << "No such username.\n";
            }
        }
        else if (result == 2)//reg
        {
            user.inputUPE();
            if (user.searchInData() == 0)
            {
                std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                if (user.serializeInData() == true)
                    std::cout << "registered successful.\n";
                else
                    std::cerr << "couldn't register you.\n";
            }
            else
            {
                std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                std::cerr << "username already exists. You may want to loggin.\n";//kzc1914 LEVSKI SHAMPION a za cska KUR OT SLON
            }
        }
        else if (result == -1)//invalid command
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            std::cerr << "invalid command.\n";
        }
        else
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            std::cerr << ";(\nFatal error like windows blue screen!\n";
        }
    }

}


void Menu::menu2(Users& user, Destinations& destination)
{
    
    int result = 100;
    globals::simpleInterface GSI;//GSI = globals simple interface
    globals::functionality FNC;//FNC = functionality

    while (true)
    {
        TripsTable emptyTravel{};
        user.setTravel(emptyTravel);
        GSI.printLookAdd();
        result = FNC.lookAddFunc(user);
        if (result == 0)//
        {
            endProgram = true;
            return;
        }
        else if (result == 3)//look
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            bool haveTrips = user.deserialize();
            if (!haveTrips)
                std::cerr << "You dont have any trips. You may want to add a new trip?\n";
            std::cout << "Please press enter to continue";
            std::cin.get();
        }
        else if (result == 4)//add
        {
            user.inputTravel();
            if (user.serialize())
            {
                destination.addInfo(user);
                std::cout << "Succeed adding trips.\n";
            }
            else
                std::cerr << "Couldn't serialize data.\n";
            std::cout << "Please press enter to continue";
            std::cin.get();
        }
        else if (result == 5)//destination review
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "Input destination:\n";
            char dest[static_namespace::MAX_STR_INPUT];
            std::cin.getline(dest, static_namespace::MAX_STR_INPUT);
            destination.setName(dest);
            destination.getInfo();
            std::cout << "Please press enter to continue";
            std::cin.get();
        }
        else if (result == 6)//add friend
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            char str[MAX_STR_INPUT];
            std::cout << "Input your friend's name: ";
            std::cin.getline(str, MAX_STR_INPUT);
            Users userFriend;
            userFriend.setUsername(str);
            if (strcmp(userFriend.getUsername(), user.getUsername()) == 0)
                std::cerr << "You can't be friend with yourself.\n";
            else if (userFriend.searchInData() == 0)
                std::cerr << "No such user.\n";
            else if (userFriend.searchInData() == -1)
                if (user.addFriend(str))
                    std::cout << "Your friendship changed correctly.\n";
            std::cout << "Please press enter to continue";
            std::cin.get();
        }
        else if (result == 7)//look friend's trip
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            char fr[MAX_STR_INPUT];
            std::cout << "Input your friend's name: ";
            std::cin.getline(fr, MAX_STR_INPUT);
            char dest[MAX_STR_INPUT];
            std::cout << "Input destination to see friend's comment about that: ";
            std::cin.getline(dest, MAX_STR_INPUT);
            user.seeFriendTrip(fr, dest);
            std::cout << "Please press enter to continue";
            std::cin.get();
        }
        else if (result == -1)
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            std::cerr << "invalid command.\n";
            std::cout << "Please press enter to continue";
            std::cin.get();
        }
        else
        {
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            std::cerr << ";(\nFatal error like windows blue screen!\n";
        }
    }
}
