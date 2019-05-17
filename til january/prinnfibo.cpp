#include<iostream>
using namespace std;
int main()
{
    int t1 = 0, t2 = 1, nextTerm = 0, n;
    cin >> n;
    cout<< t1 <<endl<< t2 <<endl;

    nextTerm = t1 + t2;

    while(nextTerm <= n)
    {
        cout << nextTerm <<endl;
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    return 0;
}
