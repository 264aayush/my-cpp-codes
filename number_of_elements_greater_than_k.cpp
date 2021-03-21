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


struct event{
    int l,r,val,pos;
};

bool comp(event a,event b){
    if(a.val==b.val){
        return a.l>b.l;
    }
    return a.val>b.val;
}
void update(int * bit,int n,int idx){
    idx+=1;
    while(idx<=n){
        bit[idx]++;
        idx+=(idx&(-idx));
    }
}

int qry(int * bit, int idx){
    int sum=0;
    while(idx>0){
        sum+=bit[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int array[n];
        loop(i,0,n)
            cin>>array[i];
        int q;
        cin>>q;
        int ql[q],qr[q],qk[q];
        loop(i,0,q)
            cin>>ql[i]>>qr[i]>>qk[i];
        event arr[n+q];
        loop(i,0,n){
            arr[i]={0,0,array[i],i};
        }
        loop(i,n,n+q){
            arr[i]={ql[i-n],qr[i-n],qk[i-n],i-n};
        }
        sort(arr,arr+n+q,comp);
        int ans[q];
        int bit[n+1];
        memset(bit,0,sizeof(bit));
        for(event i:arr){
            if(i.l==0){
                update(bit,n,i.pos);
            }
            else 
                ans[i.pos]=qry(bit,i.r)-qry(bit,i.l-1);
        }
        for(int i:ans)
            cout<<i<<" ";
        cout<<endl;

    }
    
	return 0;
}
