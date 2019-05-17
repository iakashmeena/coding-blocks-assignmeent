#include<iostream>
using namespace std;
//progrm to calculate power of 10 to some number
int power(int n){
int k=1;
for(int i=1;i<=n;i++){
    k=k*(10);
}
return k;
}
//program to count no. of digits int the given no.
int countTerms(int n){
int p=0;
while(n){
    n=n/10;
    p++;
}
return p;
}

int main(){
int n;
cin>>n;
int allDigit=countTerms(n)-1;
//cout<<allDigit;
int sumEven=0;
int sumOdd=0;
if(n<=1000000000){
    while(allDigit>=0){
    sumEven+=n/power(allDigit);
    n=n%power(allDigit);
    --allDigit;
    sumOdd+=n/power(allDigit);
    n=n%power(allDigit);
    --allDigit;

}
}
else{
    return 0;
}

cout<<sumOdd<<endl;
cout<<sumEven<<endl;
return 0;

}
