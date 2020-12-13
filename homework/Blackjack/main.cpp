#include <iostream>
#include "Deck.h"
#include "Player.h"
#include "Card.h"
#include "static_globals.hpp"
using namespace static_globals;
int main()
{
    Player players[MAX_PLAYERS];
    //build in players
    players[0] = { "Georgi Ivanov-Gonzo", 46, 7, 0.9, 0 };
    players[1] = { "Ivan Ivanov", 23, 5, 0.8, 0 };
    players[2] = { "Stanka Zlateva", 33, 5, 0.5, 0 };
    players[3] = { "Peter Petrov", 33, 5, 0.5, 0 };
    int numPlayers = 4;
    int idxPlayer = -1;
    std::cout<<"Build in players:\n";
    for(int i=0; i < numPlayers; ++i)
        std::cout<<players[i]<<std::endl;
    std::cout<<"input player name(if player doesn't exist, it will be created): ";
    char str[MAX_STR];
    std::cin.getline(str, MAX_STR);
    for(int i=0; i < numPlayers; ++i)
        if(strcmp(str, players[i].getName()) ==0)
        {
            idxPlayer = i;
            std::cout<<"Player "<<str<<" selected.\n";
            break;
        }
    if(idxPlayer<0)
    {
        std::cout<<"No such player.\nPlayer " <<str<<" has been created.\n";
        int years;
        unsigned wins;
        float win_rate;
        std::cout<<"Input years: ";
        std::cin >> years;
        std::cout<<"Input wins: ";
        std::cin >> wins;
        std::cout<<"Input win_rate: ";
        std::cin>>win_rate;
        if(years < 18 || years > 90)
        {
            std::cout<<"Sorry you can't play that game.\n";
            return 0;
        }
        idxPlayer = numPlayers;
        players[numPlayers++] = {str, years, wins, win_rate, 0}; 
    }
    std::cout<<"With how many cards you wanna play: ";
    int n;
    std::cin >> n;
    if(n<52)
    {
        std::cerr<<"Minimum cards are 52. A default deck with 52 cards will be created.\n";
        n = 52;
    }
    Deck deck(n);
    int casinoScore=0;
    bool endGame = false;    
    //Player idxPlayer plays against the Casino with the Deck deck
    //TODO: razburkvane na testeto(permutaciq)
    std::cout<<"\n\n\n*B*L*A*C*K*J*A*C*K*\n";
    Card* currCard = deck.draw();
    players[idxPlayer].setCurrentPoints(currCard->cardToPoint());
    std::cout<<"Your card: "<<*currCard<<"\n";
    currCard = deck.draw();
    casinoScore += currCard->cardToPoint();
    std::cout<<"Casino's card: "<<*currCard<<"\n";
    do
    {
        std::cout<<"Your points: " << players[idxPlayer].getCurrentPoints()
            <<std::endl<<"Casino's points: "<<casinoScore<<std::endl;
        char cmd = 'Z';
        std::cout<<"Please input command H or F\n(H-for Hit, F-for fold)\n";
        std::cin>>cmd;
        if(cmd == 'H' || cmd == 'h')
        {
            currCard = deck.draw();
            std::cout<<"You picked:\n";
            std::cout<<*currCard<<"\n";
            players[idxPlayer].setCurrentPoints(players[idxPlayer].getCurrentPoints() + currCard->cardToPoint());
            if(currCard->cardToPoint() == 11 && players[idxPlayer].getCurrentPoints() > 21)
                players[idxPlayer].setCurrentPoints(players[idxPlayer].getCurrentPoints() - 10);
            if(players[idxPlayer].getCurrentPoints() == 21)
            {
                std::cout<<"Your points: "<<players[idxPlayer].getCurrentPoints()<<" " <<"Casino's points: "<<casinoScore<<"\n";
                std::cerr<<"BLACKJACK!\nYou win.\n";
                endGame = true;
                return 0;
            }
            else if(players[idxPlayer].getCurrentPoints() > 21)
            {
                std::cout<<"Your points: "<<players[idxPlayer].getCurrentPoints()<<" " <<"Casino's points: "<<casinoScore<<"\n";
                std::cerr<<"You lose.\n";
                endGame = true;
                return 0;
            }
        }
        else if(cmd == 'F' || cmd == 'f')
        {
            do
            {
                currCard = deck.draw();
                std::cout<<"Casino picked:\n";
                std::cout<<*currCard<<"\n";
                casinoScore += currCard->cardToPoint();
                if(currCard->cardToPoint() == 11 && casinoScore > 11)
                    casinoScore -= 10;

            }while(casinoScore <= 17);
            if(casinoScore > 21)
            {
                std::cout<<"Your points: "<<players[idxPlayer].getCurrentPoints()<<" " <<"Casino's points: "<<casinoScore<<"\n";
                std::cout<<"You win.\n";
                endGame = true;
                return 0;
            }
            else
            {
                if(casinoScore == players[idxPlayer].getCurrentPoints())
                {
                    std::cout<<"Your points: "<<players[idxPlayer].getCurrentPoints()<<" " <<"Casino's points: "<<casinoScore<<"\n";
                    std::cout<<"Draw.\n";
                    endGame = true;
                    return 0;
                }
                else if(casinoScore < players[idxPlayer].getCurrentPoints())
                {
                    std::cout<<"Your points: "<<players[idxPlayer].getCurrentPoints()<<" " <<"Casino's points: "<<casinoScore<<"\n";
                    std::cout<<"You win.\n";
                    endGame = true;
                    return 0;
                }
                else
                {
                    std::cout<<"Your points: "<<players[idxPlayer].getCurrentPoints()<<" " <<"Casino's points: "<<casinoScore<<"\n";
                    if(casinoScore == 21)
                        std::cout<<"BLACKJACK!\n";
                    std::cout<<"You lose.\n";
                    endGame = true;
                    return 0;
                }
            }
        }
        else
            std::cerr<<"unknown command.\n";
    }while(!endGame);
    
    
    return 0;
}