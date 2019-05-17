#include <iostream>

using namespace std;

int main()
{
int arr[4]={1,2,3,4};
int n =4;
for(int i=0;i<n;i++)
{
    for(int j=i;j<n;j++)
    {
        for(int p=i;p<=j;p++)
        {
            cout<<arr[p];
        }
        cout<<endl;
    }

}

    return 0;
}
