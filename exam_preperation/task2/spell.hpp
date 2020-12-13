#ifndef _SPELL
#define _SPELL
#define MAX_LEN 150

class Spell
{
private:
        char description[MAX_LEN];
        int type;
        double mana_needed;
public:
        Spell() = default;
        Spell(const Spell& other) = default;
        Spell(const char *_description, int _type, double _mana_needed);
        Spell& operator=(const Spell& other) = default;
        ~Spell() = default;
};

#endif