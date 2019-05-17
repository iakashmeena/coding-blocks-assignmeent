#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main() {
    char c, u;
    char fname[10];

    ofstream out;
    cout << "Enter File Name:";
    cin>>fname;
    out.open(fname);
    cout << "Enter the text(Enter # at end)\n";
    while ((c = getchar()) != '#') {
        u = c - 32;
        out << u;
    }
    out.close();
    ifstream in(fname);
    cout << "\n\n\t\tThe File contains\n\n";
    while (in.eof() == 0) {
        in.get(c);
        cout << c;
    }
}
