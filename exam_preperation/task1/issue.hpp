#ifndef _ISSUE
#define _ISSUE
#define EPS 0.001
#include <iostream> 

class Issue
{
private:
        char *title;
        float price; //positive    
        unsigned int quantity;
public:
        //big four
        Issue();
        Issue(const Issue& other);
        const Issue& operator=(const Issue& other);
        ~Issue();

        //selectors & mutators
        //sel
        const char *get_title() const;
        float get_price() const;
        unsigned int get_quantity() const;
        //mut
        void set_title(const char *_title);
        void set_price(float _price);
        void set_quantity(unsigned int _quantity);

        //operators
        friend std::istream& operator>>(std::istream& is, Issue& obj);
        friend std::ostream& operator<<(std::ostream& os, const Issue& obj);
       
        //helpers
        void copy(const Issue& other);
        void clear();
};

#endif