#include <iostream>

using namespace std;
struct time
{
    int second;
    int minute;
    int hour;
};
void input_time(time* t){
    cout<<"enter the time"<<endl;
    cin>>t->second;
    cin>>t->minute;
    cin>>t->hour;
}
void print_time(time t){
    cout<<"display time of "<<endl;
    cout<<t.second<<":";
    cout<<t.minute<<":";
    cout<<t.hour;
}
time dif(time t1,time t2){

}

int main()
{
   time t1,t2;
   input_time(&t1);
   print_time(t1);
   input_time(&t2);
   print_time(t2);
   dif(t1,t2);
   return 0;
}
