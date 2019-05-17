#include<iostream>
using namespace std;
int main(){
int *ptr=new int;

*ptr=8;
cout<<*ptr<<endl;
delete ptr;
cout<<*ptr;
}
