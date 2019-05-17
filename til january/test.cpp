#include <iostream>
using namespace std;

bool RatInMaze(char maze[][1000],int i,int j,int m,int n,int sol[][1000]){
	// base case
	if(i==m-1 && j==n-1){
		sol[i][j]=1;
		for(int k=0;k<m;k++){
			for(int l=0;l<n;l++){
				cout<<sol[k][l]<<" ";
			}cout<<endl;
		}
		return true;
	}

	// Recursive case
	sol[i][j]=1;
	if(j+1<n && maze[i][j+1]!='X'){
		bool KyaRightSeBaatBani=RatInMaze(maze,i,j+1,m,n,sol);
		if(KyaRightSeBaatBani){
			return true;
		}
	}

	if(i+1<m && maze[i+1][j]!='X'){
		bool KyaNeecheSeBaatBani=RatInMaze(maze,i+1,j,m,n,sol);
		if(KyaNeecheSeBaatBani){
			return true;
		}
	}
	sol[i][j]=0;
	return false;

}

int main(){
	char maze[1000][1000];
	int m,n;
	int sol[1000][1000]={0};
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
	    for(int j=0;j<n;j++){
	        cin>>maze[i][j];
	    }
	}

	RatInMaze(maze,0,0,m,n,sol);

	return 0;
}
