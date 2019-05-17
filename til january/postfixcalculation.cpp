#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
//stack using vector
template<typename T>
class stack{
    vector<T>v;
public:
    bool isempty(){
        if(v.size()==0){
            return 1;
        }
        return 0;
    }
    void push(T data){
        v.push_back(data);
    }
    void pop(){
        if(isempty()==1){
            return;
        }
        v.pop_back();
    }
    int size(){
        return v.size();
    }
    T top(){
        if(isempty()){
            return NULL;
        }
        return v[v.size()-1];
    }

};

int power(int n){
    if(n==0){
        return 1;
    }
    int temp=1;
    for(int i=1;i<=n;i++){
        temp=temp*10;
    }
    return temp;
}

int main()
{
    stack<int>s;
    //int arr[100];k kbbdkbeakuyidgdbvmn jcuicsb cnhcsgmdjd c,a b jba.kx czajbjmZ KYhmbj, kxyjhb,ṣ
    }
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0;
    while(i<n){
        if(arr[i]=='+'){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            int temp=b+a;
            s.push(temp);
        }
        else if(arr[i]=='-'){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            int temp=b-a;
            s.push(temp);
        }
        else if(arr[i]=='*'){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            int temp=b*a;
            s.push(temp);
        }
        else if(arr[i]=='/'){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            int temp=b/a;
            s.push(temp);
        }
        else {
            int a=arr[i]-48;
            cout<<a<<" ";
            s.push(a);
        }
        ++i;
    }
    cout<<endl;
    cout<<s.top();
}
