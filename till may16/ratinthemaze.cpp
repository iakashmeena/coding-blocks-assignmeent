#include<iostream>
using namespace std;
bool ratinthemaze(char maze[][100],int sol[][100],int n,int m,int row,int col){
    if(row==n-1 && col==m-1){
           if(maze[row][col]=='X'||maze[row][col]=='x'){
                return false;
            }
        sol[row][col]=1;
        return true;
    }
    if(row>n-1||col>m-1){
        return false;
    }
    if(row<0||col<0){
        return false;
    }
    if(maze[row][col]=='X'||maze[row][col]=='x'){
        return false;
    }

    sol[row][col]=1;

    bool right=ratinthemaze(maze,sol,n,m,row,col+1);
    if(right==true){
        return true;
    }

    bool down=ratinthemaze(maze,sol,n,m,row+1,col);
    if(down==1){
        return true;
    }

    sol[row][col]=0;

    return false;
}
int main()
{
    int n;
    int m;
    char maze[100][100];
    int sol[100][100]={0};
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    bool x=ratinthemaze(maze,sol,n,m,0,0);
    if(x==0){
        cout<<"-1";
        return 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<sol[i][j]<<" ";
            }
        cout<<endl;
        }
}
