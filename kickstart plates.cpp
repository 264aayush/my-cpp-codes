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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    loop(t,1,tc+1){
        cout<<"Case #"<<t<<": ";
        int n,k,p;
        cin>>n>>k>>p;
        ll arr[n][k];
        loop(i,0,n)
            loop(j,0,k)
                cin>>arr[i][j];
        loop(i,0,n)
            loop(j,0,k-1)
                arr[i][j+1]+=arr[i][j];
        ll dp[n+1][p+1];
        memset(dp,0,sizeof(dp));
        for(int stk=1;stk<=n;stk++){
            for(int plates=1;plates<=p;plates++){
                ll ans=dp[stk-1][plates];
                for(int i=1;i<=plates;i++){
                    if(i-1<k)
                    ans=max(ans,arr[stk-1][i-1]+dp[stk-1][plates-i]);
                }
                dp[stk][plates]=ans;
            }
        }
        cout<<dp[n][p]<<endl;




    }
    
	return 0;
}
