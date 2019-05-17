#include<iostream>
using namespace std;
int main()
{
char ch;
long n,m;
cin>>ch;
if(ch!='x' && ch!='X'){
        while(ch!='X' && ch!='x'){
    switch(ch){
    case '+':{

        cin>>n;

        cin>>m;
        cout<<m+n;
        break;
    }
    case'-':{

        cin>>n;

        cin>>m;
        cout<<n-m<<endl;
        break;
    }
    case'*':{

        cin>>n;

        cin>>m;
        cout<<n*m<<endl;
        break;
    }
    case'/':{

        cin>>n;

        cin>>m;
        cout<<n/m<<endl;
        break;
    }
    case'%':{

        cin>>n;

        cin>>m;
        cout<<n%m<<endl;
        break;
    }

    default:{
        cout<<"invalid operation";
    }


    }
    cin>>ch;
    }

}
else{
    cout<<"invalid operation";
}

return 0;
}
