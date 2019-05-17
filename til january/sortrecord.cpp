#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct student{
    char name[100];
    int data;

};

int main()
{
    student s[100];
    int n;
    cout<<"enter no. of records : ";
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++){
        char arr[100];
        cout<<"enter the name : ";
        cin.getline(s[i].name,100);
        cout<<"enter the roll no : ";
        cin>>s[i].data;
        cin.get();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(strcmp(s[j].name,s[j+1].name)>0)

            {
                char temp[100];
                strcpy(temp,s[j].name);
                strcpy(s[j].name,s[j+1].name);
                strcpy(s[j+1].name,temp);
                int tempo;
                tempo=s[j].data;
                s[j].data=s[j+1].data;
                s[j+1].data=tempo;
            }
        }
    }
    cout<<endl;
    cout<<"***************************************";
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<s[i].name;
        cout<<endl;
        cout<<s[i].data;
        cout<<endl;
    }

}

