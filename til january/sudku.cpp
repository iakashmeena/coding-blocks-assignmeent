#include<iostream>
#include<math.h>
using namespace std;

bool issafe(int arr[][100],int n,int row,int col,int i ){
    for(int j=0;j<n;j++){
        if(arr[row][j]==i){
            return false;
        }
    }
    for(int j=0;j<n;j++){
        if(arr[j][col]==i){
            return false;
        }
    }
    int sqr=sqrt(n);
    int x=(row/sqr)*sqr;
    int y=(col/sqr)*sqr;
    for(int k=x;k<x+sqr;k++){
        for(int p=y;p<y+sqr;p++){
            if(arr[k][p]==i){
                return false;
            }
        }
    }
    return true;

}

bool solvesudku(int arr[][100],int n,int row,int col){
    if(col==n){
        return solvesudku(arr,n,row+1,0);
    }
    if(row==n){
       /* for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return true;
    }

    for(int i=1;i<=n;i++){
        if(arr[row][col]!=0){
            return solvesudku(arr,n,row,col+1);
        }
        if(issafe(arr,n,row,col,i)==1){
            arr[row][col]=i;
            bool check=solvesudku(arr,n,row,col+1);
            if(check==1){
                return true;
            }
            arr[row][col]=0;
        }
    }
    return false;
}

int main()
{
    int arr[100][100];

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    solvesudku(arr,n,0,0);


    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

}
/*
bool issafe(int arr[][9],int n,int row,int col,int i){
    for(int k=0;k<n;k++){
        if(arr[row][k]==i){
            return false;
        }
    }
    for(int k=0;k<n;k++){
        if(arr[k][col]==i){
            return false;
        }
    }
    int y=row/3;
    if(y==0){
        y=0;
    }
    if(y==1){
        y=3;
    }
    if(y==2){
        y=6;
    }

    int x=col/3;
    if(x==0){
        x=0;
    }
    if(x==1){
        x=3;
    }
    if(x==2){
        x=6;
    }
    for(int k=y;k<=y+2;k++){
        for(int p=x;p<=x+2;p++){
            if(arr[k][p]==i){
                return false;
            }
        }
    }
    return true;
}

bool solvesudku(int arr[][9],int n,int row,int col){
    if(row==n){
       for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(col==n){
        return solvesudku(arr,n,row+1,0);
    }
    for(int i=1;i<10;i++){
        if(arr[row][col]!=0){
            return solvesudku(arr,n,row,col+1);
        }
        if(issafe(arr,n,row,col,i)==1){
            arr[row][col]=i;
            bool callnext=solvesudku(arr,n,row,col+1);
            if(callnext==true){
            return true;
            }
            arr[row][col]=0;
        }


    }
    return false;
}

int main()
{
    int arr[9][9]={{5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}};
    solvesudku(arr,9,0,0);

}





/*bool issafe(int arr[][10],int i,int j,int num){
    for(int k=j;k>=0;k--){
        if(arr[i][k]==num){
            return false;
        }
    }
    for(int k=i;k>=0;k--){
        if(arr[k][i]==num){
            return false;
        }
    }
    int y=i/3;
    if(y==0){
        y=0;
    }
    else if(y==1){
        y=3;
    }
    else if(y==2){
        y=6;
    }

    int x=j/3;
    if(x==0){
        x=0;
    }
    else if(x==1){
        x=3;
    }
    else if(x==2){
        x=6;
    }
    for(int k=y;k<=y+2;k++){
        for(int p=x;p<=x+2;p++){
            if(arr[k][p]==num){
                return false;
            }
        }
    }
    return true;
}
bool sudku(int arr[][10],int i,int n){
    if(i==n){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for(int j=0;j<9;j++){
        if(arr[i][j]!=0){
            continue;
        }
        for(int num=1;num<10;num++){
            if(issafe(arr,i,j,num)==1){
            arr[i][j]=num;
            }
        }

    }
    bool checked=sudku(arr,i+1,n);
    if(checked==1){
        return true;
    }
    return false;
}
int main()
{
    int arr[10][10]={{5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}};
    sudku(arr,0,9);


}
*/
/*0
0
0
1
0
6
6
0
4
0
0
0
1
0
2
0
0
0
0
0
0
5
0
1
0
0
0
6
0
3
5
0
6
0
0
0*/
