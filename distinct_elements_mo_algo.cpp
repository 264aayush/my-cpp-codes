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
int blocks;

struct query{
    int l,r,pos;
};

bool comp(query a,query b){
    if(a.l/blocks == b.l/blocks)
        return a.r<b.r;
    return a.l<b.l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        blocks=(int) sqrt(n);
        int arr[n];
        loop(i,0,n){
            cin>>arr[i];
        }
        int q;
        cin>>q;
        query qarr[q];
        loop(i,0,q){
            cin>>qarr[i].l>>qarr[i].r;
            qarr[i].pos=i;
        }
        sort(qarr,qarr+q,comp);
        int freq[1000];
        memset(freq,0,sizeof(freq));
        int count=0,currL=qarr[0].l,currR=qarr[0].r;
        loop(i,currL,currR+1){
            if(freq[arr[i]]==0)
                count++;
            freq[arr[i]]++;
        }
        int ans[q];
        for(auto i:qarr){
            while(currL<i.l){
                if(freq[arr[currL]]==1)
                    count--;
                freq[arr[currL]]--;
                currL++;
            }
            while(currL>i.l){
                if(freq[arr[--currL]]==0)
                    count++;
                freq[arr[currL]]++;
            }
            while(currR<i.r){
                if(freq[arr[++currR]]==0)
                    count++;
                freq[arr[currR]]++;
            }
            while(currR>i.r){
                if(freq[arr[currR]]==1)
                    count--;
                freq[arr[currR]]--;
                currR--;
            }
            ans[i.pos]=count;
        }
        for(int i:ans)
            cout<<i<<" ";
        cout<<endl;

    }
    
	return 0;
}
