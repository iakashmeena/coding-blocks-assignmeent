/*
STACK -- DUPLICATE PARENTHESIS
Check for duplicate parenthesis in an expression


Input Format:
First line contains T, the number of testcases. Then each testcase contains a string in which we check for duplicacy.
*/

#include<bits/stdc++.h>
using namespace std;
bool isDuplicate(string c){
    if(c[0]=='\0'){
        return 0;
    }

    bool check=0;
    stack<char> s;
    int i=0;

    while(c[i]!=NULL){
        if(c[i]>=40 && c[i]<=47){
            if(c[i]==')'){
                if(s.top()=='('){
                    check=1;
                    return check;
                }
            }

            else{
                s.push(c[i]);
            }
        }
        i++;
    }
    return check;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        string c;
        cin>>c;
        if(isDuplicate(c)==1){
            cout<<"Duplicate Found"<<endl;
        }
        else{
            cout<<"No Duplicates Found"<<endl;
        }
    }
}
