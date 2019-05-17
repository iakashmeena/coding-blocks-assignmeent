#include <iostream>
#include<stdio.h>

using namespace std;

class  student{
int a;
public:

        void marks(){
        cout<<"enter the marks";
        cin>>a;
        }
        void showmarks(){

cout<<a<<"\n";
}

int total(){
    int tot=a;
    return tot;
}


};
int main(){
//student *p2=new student;
student *p1=new student;
//p2->marks();
//p2->showmarks();
p1->marks();
p1->showmarks();
int k=p1->total();
if(k<40){
delete p1;
    cout<<"fyyhfj"<<endl;
}
p1->showmarks();

return 0;
}
