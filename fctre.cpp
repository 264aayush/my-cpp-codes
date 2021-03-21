#include <bits/stdc++.h>
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
    public:
    int V;
    vector<int> * adj;
    
    Graph(){}
    Graph(int v){
        V=v;
        adj=new vector<int>[V];
    }
    void addedge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    
};


vector<int> bfs(Graph g,int u,int v){
    vector<int> ans;
    if(u==v){
        ans.push_back(u);
        return ans;
    }
    int n=g.V;
    int prev[n];
    memset(prev,-1,sizeof(prev));
    prev[u]=u;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int pt=q.front();
        if(pt==v)
            break;
        q.pop();
        for(int i=0;i<g.adj[pt].size();i++){
            if(prev[g.adj[pt][i]]==-1){
                prev[g.adj[pt][i]]=pt;
                q.push(g.adj[pt][i]);
            }
        }
    }
    ans.push_back(v);
    for(int i=v;prev[i]!=i;){
        ans.push_back(prev[i]);
        i=prev[i];
    }
    return ans;
}

int fun(vector<int> arr){
    unordered_map<int,int> mls;
    for(int n:arr){
        while(n!=1){
            if(n%2==0){
                mls[2]++;
                n/=2;
            }
            else{
                bool divisible=false;
                for(int i=3;i*i<=n;i+=2){
                    if(n%i==0){
                        divisible=true;
                        mls[i]++;
                        n/=i;
                        break;
                    }
                }
                if(!divisible){
                    mls[n]++;
                    n=1;
                }
            }
        }
    }
    long long ans=1;
    int mod=1e9+7;
    for(auto itr=mls.begin();itr!=mls.end();itr++){
            ans=(ans*( (itr->second) +1))% mod;
    }
    return ans;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=intscan();
    while(t--){
        int n=intscan();
        Graph graph(n);
        loop(i,0,n-1){
            int u=intscan();
            int v=intscan();
            u--;v--;
            graph.addedge(u,v);
        }
        int arr[n];
        loop(i,0,n)
            arr[i]=intscan();
        int q=intscan();
        while(q--){
            int u=intscan();
            int v=intscan();
            
            u--;v--;
            vector<int> ans=bfs(graph,u,v);
            loop(i,0,ans.size()){
                ans[i]=arr[ans[i]];
            }
            
            int ret_val=fun(ans);
            printint(ret_val);
            printf("\n");
        }
    }
    
	return 0;
}
