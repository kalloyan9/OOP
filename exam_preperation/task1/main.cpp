#include <iostream>

#include "issue.hpp"
#include "subscription.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() 
{
        Issue a;
        cin >> a;
/* test
        cout << a << endl;
        cout << a.get_title() << " " << a.get_price() << " " << a.get_quantity() << endl;
*/
        Issue b;
        cin >> b;

        Issue c;
        cin >> c;

        Issue d(c);

        Subscription arr;
        arr+=a;
        arr+=b;
        arr+=c;
        arr+=d;

        for(int i = 0; i < 4; ++i)
                cout << arr[i] << endl;

        return 0;
}