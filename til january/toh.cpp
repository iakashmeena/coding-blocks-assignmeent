#include<iostream>
using namespace std;
int toh(int n,char src[],char help[],char dest[]){
    if(n==0){
        return 0;
    }
    static int k=0;
    toh(n-1,src,dest,help);
    cout<<"move "<<n<<"th disc"<<" from "<<src<<" to "<<dest<<endl;
    k++;
    toh(n-1,help,src,dest);
    return k;

}
int main()
{
    //int n=3;
    char t1[3]={"T1"};
    char t3[3]={"T3"};
    char t2[3]={"T2"};
    int n;
    cin>>n;

    cout<<toh(n,t1,t3,t2);
}
