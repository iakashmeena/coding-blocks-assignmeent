#include<iostream>
using namespace std;

class fruit{
    bool is_sweet;
    bool is_fruit;
public:
    bool is_raw;
};

class mango:public fruit{
public:
    int x=10;
};


int main()
{
    mango m;
    cout<<sizeof(mango);
}
