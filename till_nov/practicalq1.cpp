#include<iostream>
#include<fstream>
//#include<stdio.h>
using namespace std;

int main() {
    char c, u;
    char fname[10];
    ofstream out;
    cout << "Enter File Name:";
    cin>>fname;
    out.open(fname);
    cout << "Enter the data in file"<<endl;
    while ((c = getchar()) != '#') {
        u = c - 32;
        out << u;
    }
    out.close();
    ifstream in(fname);
    cout << "\nThe File contains\n";
    while (in.eof() == 0) {
        in.get(c);
        cout << c;
    }
    return 0;



//return 0;
}
