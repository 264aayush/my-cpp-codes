#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

class maxheap{
    int* heap;
    int heap_size;
    int capacity;
    public:
    maxheap(){}
    maxheap(int n){
        heap=new int[n];
        heap_size=0;
        capacity=n;
    };
    void heapifyup(int i){
        while(i>0 && heap[i]>heap[(i-1)/2]){
            swap(heap[i],heap[(i-1)/2]);
            i=(i-1)/2;
        }
    }
    void insert(int n){
        if(heap_size==capacity){
            cout<<"heap full";
            return;
        }
        heap[heap_size++]=n;
        heapifyup(heap_size-1);
    }
    
    void heapifydown(int i){
        int largest=i;
        if(2*i+1 < heap_size && heap[2*i+1]>heap[largest])
            largest=2*i+1;
        if(2*i+2 < heap_size && heap[2*i+2]>heap[largest])
            largest=2*i+2;
        if(largest!=i){
            swap(heap[i],heap[largest]);
            heapifydown(largest);
        }
    }
    void increasekey(int i,int n){
        heap[i]=n;
        heapifyup(i);
    }
    int extractmax(){
        swap(heap[--heap_size],heap[0]);
        heapifydown(0);
        return heap[heap_size];
    }
};


int main() {
    maxheap heap(1000);
    int x;
    for(int i=10;i>0;i--){
        cin>>x;
        heap.insert(x);
    }
    for(int i=10;i>0;i--)
        cout<<heap.extractmax()<<" ";
	return 0;
}
