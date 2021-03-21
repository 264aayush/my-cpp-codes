#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

inline int intscan(){
    char ch=getchar();
    while(ch < '0' || ch > '9' || ch!='-')
        ch=getchar();
    bool neg=false;
    if(ch=='-'){
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
    int t=intscan();
    while(t--){
        int n=intscan();
        int arr[n];
        loop(i,0,n)
            arr[i]=intscan();
        int ans=0,count=1;
        for(int i=0;i<n;i++){
            if(arr[i]==0)
                count++;
            else if(arr[i]==1){
                ans+=count;
                count=1;
            }
            count=1;
        }
        printint(ans);
        putchar('\n');
    }
    
	return 0;
}
