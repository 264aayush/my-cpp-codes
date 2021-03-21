#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

inline int intscan(){
    char ch=getchar();
    bool neg=false;
    while( ch < '0' || ch > '9' ){
        if(ch=='-')
            neg=true; 
        ch=getchar();   
    }
    int x=0;
    while(ch>='0' && ch<='9'){
        x=(x<<3) + (x<<1) + ch-48;
        ch=getchar();
    }
    if(neg)
        return -1*x;
    return x;
}
inline void printint(int x){
    char str[20];
    if(x<0){
        putchar('-');
        x=x*-1;
    }
    int i=0;
    do{
        str[i++]=(x%10)+'0';
        x=x/10;
    }while(x>0);
    i--;
    while(i>-1)
        putchar(str[i--]);
}

class Graph{
    int V;
    vector<int> * adj;
    public:
    Graph(){}
    Graph(int v){
        V=v;
        adj=new vector<int>[V];
    }
    void addedge(int u,int v){
        adj[u].push_back(v);
    }
    
};

void quicksort(int arr[], int l , int r){
    if(l<r){
        int pivot=r;
        int j=l;
        loop(i,l,r){
            if(arr[pivot]>arr[i])
                swap(arr[i],arr[j++]);
        }
        swap(arr[r],arr[j]);
        quicksort(arr,l,j-1);
        quicksort(arr,j+1,r);
    }
}

int main(){
    int t;
    cin>>t;
    loop(tc,1,t+1){
        int n;
        cin>>n;
        int arr[n];
        loop(i,0,n)
            cin>>arr[i];
        quicksort(arr,0,n-1);        
        int max_len=0,min_len=n,count=1;
        loop(i,1,n){
            if(arr[i]<=arr[i-1]+2)
                count++;
            else {
                min_len=min(min_len,count);
                count=1;   
            }
            max_len=max(max_len,count);
        }
        min_len=min(min_len,count);
        cout<<min_len<<" "<<max_len<<endl;

    }
}