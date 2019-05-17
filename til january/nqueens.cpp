#include<iostream>
using namespace std;
bool issafe(int arr[][11],int i,int j,int n){
    //for columns is safe
    for(int k=0;k<i;k++){
        if(arr[k][j]==1){
            return false;
        }
    }
    int y=i;
    int k=j;
    while(y>=0&&k>=0){
        if(arr[y][k]==1){
            return false;
        }
        --y;
        --k;
    }
    y=i;
    k=j;
    while(y>=0&&k<n){
        if(arr[y][k]==1){
            return false;
        }
        --y;
        ++k;
    }
    return true;
}
bool nqueens(int arr[][11],int i,int n){
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1){
                    cout<<" Q ";
                }
                else{
                    cout<<" _ ";
                }

            }
            cout<<endl;
        }
        cout<<endl<<endl;
        return true;
    }
    //int number=0;
    for(int j=0;j<n;j++){
        if(issafe(arr,i,j,n)==1){
            arr[i][j]=1;
             bool ischecked=nqueens(arr,i+1,n);
           /* if(ischecked==1){
                 return true;
            }*/
            arr[i][j]=0;

        }
    }
    return false;

}
int main()
{
    int arr[11][11]={0};
    int i=0;
    int n;
    cin>>n;
    cout<<nqueens(arr,i,n)<<endl;

}
