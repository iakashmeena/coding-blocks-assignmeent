/*#include<iostream>
using namespace std;
int countdigit(int n){
    int p=2;
    while(n){
        n=n/10;
        p++;
    }
    return p;
}
int power(int n){
    int k=1;
    for(int i=0;i<n;i++){
        k=k*10;
    }
    return k;
}
int biggest(int n,int m){
    int p,p2;
    int n1=n;
    int m1=m;
    if(m==n){
        return m;
    }


    else{
        p=countdigit(n)-1;
        p2=countdigit(m)-1;


    while(p>=0 || p2>=0){

        if(n1/power(p)>m1/power(p2)){
            return n;
        }
        else if(n1/power(p)<m1/power(p2)){
            return m;
        }
        else{
            n1=n1%power(p);
            m1=m1%power(p2);
        }
        --p;
        --p2;
    }
}

}

int main()
{
    int t;
    cin>>t;
    int index;

    while(t){
        int n;
        cin>>n;
        int arr[100];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            int largest=0000000;
            int index;
            for(int j=i;j<n;j++){
                largest=biggest(largest,arr[j]);
            }
            for(int k=0;k<n;k++){
                if(largest==arr[k]){
                    index=k;
                }
            }
            int temp=arr[index];
            arr[index]=arr[i];
            arr[i]=temp;
        }

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    --t;
    cout<<endl;
}
}
*/
#include<iostream>
using namespace std;
int countdigit(int n){
    int p=0;
    while(n){
        n=n/10;
        p++;
    }
    return p;
}
int power(int n){
    int k=1;
    for(int i=0;i<n;i++){
        k=k*10;
    }
    return k;
}
int biggest(int n, int m){
    int c=countdigit(m);
    int k=n*power(c)+m;
    return k;
}
int main()
{
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        int arr[1000];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                int p=biggest(arr[j],arr[j+1]);
                int k=biggest(arr[j+1],arr[j]);
                if( p < k ){
                    //cout<<"true"<<endl;
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
    }

}
