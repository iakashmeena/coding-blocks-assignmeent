#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;
int fact(int n){
    if(n==1){
        return 1;
    }
return fact(n-1)*n;
}



/*
int fibo(int n){
if(n==1){
    return 0;
}
if(n==2){
    return 1;
}
int a=fibo(n-2);
int b=fibo(n-1);
int c=a+b;
cout<<c<<endl;
return c;
}*/
int fibo(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    int a = fibo(n-2);
    int b = fibo(n-1);
    int c = a+b;
    cout<<c<<endl;
    return c;
}
int main(){
int n=fibo(5);
cout<<n;

return 0;
}

/*struct node{
int data;
node *next;
};
node *create(){
    node *head=new node;
    int data;
    cout<<"enter the data";
    cin>>data;
    if(data!=-1){
        head->data=data;
        head->next=NULL;
    }
    node*it=head;
    cin>>data;
    while(data!=-1){
        node *temp=new node;
        temp->data=data;
        temp->next=NULL;
        it->next=temp;
        it=it->next;
        cin>>data;

    }
    return head;

}

void shownodes(node *head){
    int i=0;
while(head!=NULL){
    cout<<head->data<<endl;
    head=head->next;
}
}

int main(){
node *head=create();

shownodes(head);
}
void deleteatk(node*head,int k){
node * temp=new node;
int data;
cout<<"enter data";
cin>>data;
temp->data=data;
if(k==0){
    temp->next=head;
    head=temp;
    return;
}
node *it=head;
while(--k){
    it=it->next;
}
temp->next=it->next;
it
}*/
/*class student{
int marks;
int roll;
public:
    void getdata(){
        cout<<"enter marks and roll ";
        cin>>roll>>marks;
    }
    void showdata(){
    cout<<"roll "<<roll;
    cout<<"\nmarks"<<marks;
    }
};

int main(){

int i=-1,j=-1,k=0,l=0,m;
m=++i && ++j && k++ || l;
cout<<i;
cout<<m;
*/
/*student s;
fstream fil;
fil.open("sus.dat",ios::in|ios::out);
cout<<"enter the details";

    s.getdata();
    fil.write((char*)&s,sizeof(s));

    fil.seekg(0);
    cout<<"the contents of the file ";
    fil.read((char*)&s,sizeof(s));
    s.showdata();
    fil.close();

*/

/*char fname[10];
ofstream fout;
cout<<"enter the name of file";
gets(fname);
fout.open("sus");
fout<<"sushant";
fout.close();
char line[80];
ifstream fin;
fin.open("sus");
cout<<"the contents"<<endl;
fin.getline(line,80);
cout<<line;

}*/
