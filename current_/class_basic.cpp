#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Complex{
    int real;
    int img;
public:
    void setComplex(int real,int img){
        this->real=real;
        this->img=img;
    }
    void setReal(int real){
        this->real=real;
        return;
    }
    void setImg(int img){
        this->img=img;
        return;
    }
    int getReal()const{
        return real;
    }
    int getImg()const{
        return img;
    }
    void show()const{
        if(img>0){
            cout<<real<<" + "<<img<<"i"<<endl;
            return;
        }
        else{
            cout<<real<<" - "<<-img<<"i"<<endl;
        }
    }
    ///+
    void operator+(const Complex&x){
        real+=x.getReal();
        img+=x.getImg();
        return;
    }
    ///-
    void operator-(const Complex&x){
        real-=x.getReal();
        img-=x.getImg();
        return;
    }
    ///!
    void operator!(){
        img*=-1;
    }
    ///[]
    void operator[](string s){
        cout<<real<<" + "<<img<<"i "<<s;
    }

};
    ///<<,>>
istream& operator>>(istream &cin,Complex &x){
    int r,i;
    cin>>r>>i;
    x.setReal(r);
    x.setImg(i);
    return cin;
}
ostream& operator<<(ostream &cout,Complex &x){
    x.show();
    return cout;
}

int main()
{
    Complex c;
    Complex d;
    c.setComplex(5,3);
    c.show();
    d.setImg(8);
    d.setReal(6);
    d.show();
    d+c;
    d.show();
    d-c;
    d.show();
    !d;
    d.show();
    cin>>d;
    cout<<d;
    Complex d1,d2;
    cin>>d1>>d2;
    cout<<d1<<d2;

}
