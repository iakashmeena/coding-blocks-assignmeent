#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<char>s;
    char arr[100]="{[()]}";
    int i=1;
    s.push(arr[0]);
    while(arr[i]!='\0'){
        if(s.top()== '{' && arr[i]=='}'||s.top()=='['&& arr[i]==']'||s.top()=='('&& arr[i]==')'){
            s.pop();
        }
        else{
            s.push(arr[i]);
        }
        i++;
    }
    if(s.empty()){
        cout<<"yes";
    }
    else{
        cout<<"not";
    }

}
