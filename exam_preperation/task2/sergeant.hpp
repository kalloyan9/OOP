#ifndef _SERGEANT
#define _SERGEANT
#include "soldier.hpp"
#define MAX_SOLDIERS 100

class Sergeant : public Soldier
{
private:
        char subordinates[MAX_LEN];
        Soldier soldiers[MAX_SOLDIERS];
public:
        
};
#endif