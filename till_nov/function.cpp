#include<iostream>
using namespace std;
int fact(int n){
   int fact=1;
for(int i=1;i<=n;i++){
    fact=fact*i;

}
return fact;
}
int comb(int n,int r){
    int comb;
comb=fact(n)/(fact(n-r)*fact(r));
return comb;
}

int main()
{
   // cout<<fact(10);
   cout<<comb(5,2);
}
