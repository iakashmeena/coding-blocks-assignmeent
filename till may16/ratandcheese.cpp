#include<iostream>
using namespace std;
bool ratinthemaze(char maze[][100],int sol[][100],int n,int m,int row,int col){
    if(row>n-1&&col>=m-1){
        /*for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }*/

        return true;
    }
    if(row>n-1||col>m-1){
        return false;
    }
    if(row<0||col<0){
        return false;
    }
    if(maze[row][col]=='X'){
        return false;
    }
    if(sol[row][col]==1){
        return false;
    }

    sol[row][col]=1;
    bool right=ratinthemaze(maze,sol,n,m,row,col+1);
    if(right==true){
        return true;
    }
    bool  left=ratinthemaze(maze,sol,n,m,row,col-1);
    if(left==true){
        return true;
    }
    bool down=ratinthemaze(maze,sol,n,m,row+1,col);

    if(down==1){
        return true;
    }
    bool up=ratinthemaze(maze,sol,n,m,row-1,col);
    if(up){
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
        cout<<"NO PATH FOUND";
        return 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<sol[i][j]<<" ";
            }
        cout<<endl;
        }
}
