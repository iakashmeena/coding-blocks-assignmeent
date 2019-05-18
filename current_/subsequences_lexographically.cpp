#include<bits/stdc++.h>
using namespace std;
void printLexo(string &s,char c[],set<string> &sub,int i,int j){
    if(s[i]==NULL){
        c[j]='\0';
        sub.insert(c);
        return;
    }

    printLexo(s,c,sub,i+1,j);
    c[j]=s[i];
    printLexo(s,c,sub,i+1,j+1);


}
int main()
{
    int n;
    cin>>n;
    set<string>sub;
    char c[100];
    while(n){
        string s;
        cin>>s;
        printLexo(s,c,sub,0,0);
        for(auto i:sub){
            cout<<i<<endl;
        }
        --n;
    }
}
