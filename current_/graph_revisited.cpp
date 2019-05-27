#include<bits/stdc++.h>
using namespace std;
template<typename T>
class heap{
    vector<T>v;
    bool if_min;
public:
    heap(bool if_min=1){
        v.push_back(-1);//WILL PUSH -1 AT FIRST INDEX
        this->if_min=if_min;
    }
    void push(T data){
        v.push_back(data);
        int index=v.size()-1;
        int parent=index/2;
        while(index>=1 && v[parent]>v[index]){
            swap(v[parent],v[index]);
            index=index/2;
        }
        return ;
    }
    void print(){
        for(int i=1;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }
};
int main()
{
    heap<int>h(1);
    h.push(8);
    h.push(7);
    h.push(2);
    h.push(0);
    h.push(1);
    h.print();
}
