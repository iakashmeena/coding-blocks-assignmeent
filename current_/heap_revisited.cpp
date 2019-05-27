#include<bits/stdc++.h>
using namespace std;
template<typename T>
class heap{
    vector<T>v;
    bool if_minheap;
    void heapify(int i){
        int minindex=i;
        int left=2*i;
        int right=2*i+1;
        if(left<v.size()&& v[left]<v[minindex]){
            minindex=left;

        }
        if(right<v.size()&&v[right]<v[minindex]){
            minindex=right;
        }
        if(minindex!=i){
            swap(v[minindex],v[i]);
            heapify(minindex);
        }
    }
public:
    heap(bool if_minheap=1){
        v.push_back(-1);
        this->if_minheap=if_minheap;
    }
    void push(T data){
        v.push_back(data);
        int index=v.size()-1;
        int parent=index/2;
        while(index>=1 && v[parent]>v[index]){
            swap(v[parent],v[index]);
            index=parent;
            parent=parent/2;
        }
    }
    bool isempty(){
        if(v.size()>1){
            return 0;
        }
        return 1;
    }

    void pop(){
        if(isempty()==1){
            return;
        }
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }
    void print(){
        for(int i=1;i<v.size();i++){
            cout<<v[i]<<" ";
        }

    }

};
int main()
{
    heap<int>h;
    h.push(6);
    h.push(5);
    h.push(4);
    h.push(10);
    h.push(2);
    h.push(1);
    h.push(0);
    h.pop();
    h.print();
    cout<<endl;
    h.push(0);
    h.push(7);
    h.push(8);
    h.push(9);
    h.push(3);
    h.print();
}
