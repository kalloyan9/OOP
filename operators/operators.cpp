#include <iostream>

class Product
{
private:
        int id;
        double price;
public:
        Product(int _id = 0, double _price = 0.0);



        /* variant 1 */
        friend Product& operator-=(Product& pr, unsigned percent);
        friend Product operator-(const Product& pr, unsigned percent);




        /* variant 2 */
        Product& operator+=(unsigned percent);
        Product operator+(unsigned percent);


        friend std::ostream& operator<<(std::ostream& os, const Product& p);
};
Product::Product(int _id, double _price) 
        : id(_id)
        , price(_price)
{       }







/* variant 1 */
Product operator-(const Product& pr, unsigned percent) 
{
        Product cp(pr);
        return cp-=percent;
}

Product& operator-=(Product& pr, unsigned percent) 
{
        pr.price = (double) (100u - percent) / 100u * pr.price; 
        return pr;
}
/* - variant 1 */






/* variant 2 */
Product& Product::operator+=(unsigned percent) 
{
        this->price = (double) (100u + percent) / 100u * this->price;
        return *this;
}

Product Product::operator+(unsigned percent) 
{
        Product cp(*this);
        cp += percent;
        return cp;
}
/* - variant 2 */






std::ostream& operator<<(std::ostream& os, const Product& p) 
{
        std::cout << p.id << ", " << p.price << std::endl;
        return os;
}




int main() 
{
        Product a(19, 100);
        a -= 10;
        a = a - 10;
        std::cout << a;

        Product b(20, 100);
        b += 10;
        b = b + 10;
        std::cout << b;
        return 0;
}