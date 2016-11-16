#include <iostream>

using namespace std;


int main()
{


    for (int count=1; count<=100; count++)
        if (count%3!=0 && count%5!=0)
        cout<<count<<endl;
        else if (count%3==0 && count%5==0)
            cout<<"FizzBuzz"<<endl;
        else if (count%3==0 && count%5!=0)
            cout<<"Fizz"<<endl;
        else
            cout<<"Buzz"<<endl;

    return 0;


}
