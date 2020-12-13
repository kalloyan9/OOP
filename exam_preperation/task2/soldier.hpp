#ifndef _SOLDIER
#define _SOLDIER
#define MAX_LEN 150

class Soldier
{
private:
        char name[MAX_LEN];
        unsigned short ages;
        int skills;
        int wage;
public:
        Soldier() = default;
        Soldier(const char *_name, unsigned short _ages, int _skills, int _wage); //when I declarate constructor, the compiler won't the default big four
        Soldier(const Soldier& other) = default;
        Soldier& operator=(const Soldier& other) = default;
        ~Soldier() = default;
        
        void print();
};
#endif