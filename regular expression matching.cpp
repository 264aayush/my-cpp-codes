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
    cin.ignore();
    loop(tc,1,t+1){
        string ptr,str;
        getline(cin,ptr);
        getline(cin,str);

        bool dp[str.length()+1][ptr.length()+1];
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        
        
        loop(i,1,ptr.length()+1)
            if(ptr[i-1]=='*')
                dp[0][i]=dp[0][i-2];
        
        loop(i,1,str.length()+1){
            loop(j,1,ptr.length()+1){
                if(str[i-1]==ptr[j-1] || ptr[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(ptr[j-1]=='*'){
                    dp[i][j]=dp[i][j-2];
                    if(ptr[j-2]==str[i-1] || ptr[j-2]=='.')
                        dp[i][j] |= dp[i-1][j];
                }
                else dp[i][j]=false;
            }
        }
        cout<<ptr<<endl<<str<<endl;

        loop(i,0,str.length()+1){
            loop(j,0,ptr.length()+1){
                if(dp[i][j])
                    cout<<'T'<<" ";
                else cout<<'F'<<" ";
            }
            cout<<endl;
        }
        cout<<endl;


    }
}