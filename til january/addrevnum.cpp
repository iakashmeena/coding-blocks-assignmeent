#include<iostream>
using namespace std;
int rev_num(int a){
int val=a;
int num=0;
while(val>0){
    num=num*10+val%10;
    val=val/10;
}
return num;

}
int main()
{
    int t;
    int num1,num2;
    cin>>t;
    for(int i=0;i<t;i++){
        int sum=0;
        cin>>num1;
        cin.get();
        cin>>num2;
        sum=rev_num(num1)+rev_num(num2);
        cout<<rev_num(sum)<<endl;
    }
 return 0;
}
