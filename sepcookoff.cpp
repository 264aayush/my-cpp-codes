#include <bits/stdc++.h>
#define endl "\n"
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
int n;
bool comp(pair<int,int> a,pair<int,int> b){
    if(a.second-a.first==b.second-b.first){
        if(a.first==0||a.second==n-1)
            return true;
        if(b.first==0||b.second==n-1)
            return false;
    }
    return  a.second-a.first>b.second-b.first;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        ll sum=0;
        bool positive_exist=false;
        loop(i,0,n){
            cin>>arr[i];
            if(arr[i]>0){
                positive_exist=true;
                sum+=arr[i];
            }
        }
        if(!positive_exist){
            cout<<0<<endl<<0<<endl;
            continue;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0)
                count++;
        }
        // cout<<"positives: "<<count<<endl;
        vector<int> ans;
        for(int i=0;i<count;i++){
            if(arr[i]<=0){
                ans.push_back(i);
            }
        }
        for(int i=count;i<n;i++){
            if(arr[i]>0){
                ans.push_back(i);
            }
        }
        cout<<sum<<endl;
        cout<<ans.size()<<" ";
        for(int i:ans){
            cout<<i+1<<" ";
        }
        cout<<endl;

    }
	return 0;
}

