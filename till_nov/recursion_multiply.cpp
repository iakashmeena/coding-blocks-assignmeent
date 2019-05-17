#include<iostream>
using namespace std;
int multi(int b,int m){
    if(m==0){
        return 0;
    }

    int mult=multi(b,m-1);
    return mult+b;

}
int main()
{
    cout<<multi(23,0);
}
