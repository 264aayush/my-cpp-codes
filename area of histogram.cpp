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

int main(){
    int t;
    cin>>t;
    loop(tc,1,t+1){
        int n;
        cin>>n;
        int arr[n];
        loop(i,0,n)
            cin>>arr[i];
        stack<int> s;
        int i=0;
        int max_area=0;
        int area=0;
        while(i<n){
            if(s.empty()||arr[s.top()]<=arr[i]){
                s.push(i++);
            }
            else {
                int temp=s.top();
                s.pop();
                area=arr[temp]*(s.empty()?i:(i-s.top()-1)); 
                max_area=max(max_area,area);
                // cout<<"pop "<< arr[temp]<<endl;
                // cout<<"area is : "<<area<<endl;
            }


        }
        while(!s.empty()){
            int temp=s.top();
            s.pop();
            area=arr[temp]*(s.empty()?i:(i-s.top()-1)); 
            max_area=max(max_area,area);
            // cout<<"pop "<< arr[temp]<<endl;
            // cout<<"area is : "<<area<<endl;
        }
        cout<<max_area<<endl;
    }
}