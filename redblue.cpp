#include <bits/stdc++.h>
#define endl "\n"
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

struct node{
    vector<int> child;
    int excess,req; 
    bool parity;
    node(){
        excess=0;req=0;
        parity=false;
    }
};

void dfsparity(node tree[],int s,int parent=-1){
    for(int child:tree[s].child){
        if(child==parent)
            continue;
        tree[child].parity=!tree[s].parity;
        dfsparity(tree,child,s);
    }    
}

ll dfs(node tree[],int s,bool parity[],int parent=-1){
    ll ans=0;
    for(auto child:tree[s].child){
        if(child==parent)
            continue;
        ans+=dfs(tree,child,parity,s);
    }
    ll excess=0,req=0;
    for(auto child:tree[s].child){
        if(child==parent)
            continue;
        excess+=tree[child].excess;
        req+=tree[child].req;    
    }
    if(parity[s]==tree[s].parity){}
    else if(parity[s])
        excess++;
    else req++;

    ll m=min(excess,req);
    excess-=m;
    req-=m;
    
    tree[s].excess=excess;
    tree[s].req=req;

    ans+=excess;
    ans+=req;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        node tree[n];
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            x--;y--;
            tree[x].child.push_back(y);
            tree[y].child.push_back(x);    
        }
        // string s;
        // cin>>s;
        char tempch;
        bool s[n];
        loop(i,0,n){
            cin>>tempch;
            if(tempch=='0')
                s[i]=false;
            else s[i]=true;
        }
        ll ans=__LONG_LONG_MAX__;
        
        dfsparity(tree,0);
        ll temp=dfs(tree,0,s,-1);
        if(tree[0].excess==tree[0].req)
            ans=min(temp,ans);

        tree[0].parity=true;
        
        dfsparity(tree,0);
        temp=dfs(tree,0,s);
        if(tree[0].excess==tree[0].req)
            ans=min(temp,ans);
        
        if(ans!=__LONG_LONG_MAX__)
            cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    
	return 0;
}
