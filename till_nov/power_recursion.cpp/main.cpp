#include <iostream>

using namespace std;
int power(int x,int n){
    if(n==0){
        return 1;
    }
    int c=power(x,n-1);
    int p=x*c;
    return p;
}

int main()
{
    cout<<power(5,5);

    return 0;
}
