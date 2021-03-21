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

// bool match(string &ptr,string &str,int i,int j){
//     if(i==ptr.length() && j==str.length()){
//         return true;
//     }
//     if(i==ptr.length() || j==str.length()){
//         if(j==str.length() && ptr[i]=='*'){
//             return match(ptr,str,i+1,j);
//         }
        
//         return false;
//     }
//     if(ptr[i]==str[j]||ptr[i]=='?'){
//         return match(ptr,str,i+1,j+1);
//     }
//     if(ptr[i]=='*'){
//         if(match(ptr,str,i+1,j))
//             return true;
//         for(int x=j+1;x<=str.length();x++){
//             if(match(ptr,str,i+1,x))
//                 return true;
//         }
//     }
//     return false;
// }

bool match(string ptr,string str){
    int n=ptr.length();
    int m=str.length();
    
    bool dp[m+1][n+1];
    memset(dp,false,sizeof(dp));
    dp[0][0]=true;
    
    for(int i=1;i<=ptr.length();i++){
        if(ptr[i-1]!='*')
            break;
        dp[0][i]=true;
    }
    for(int i=1;i<=str.length();i++){
        for(int j=1;j<=ptr.length();j++){
            if(ptr[j-1]==str[i-1]||ptr[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];
            else if(ptr[j-1]=='*'){
                dp[i][j]=dp[i-1][j]|dp[i][j-1];
            }
            else dp[i][j]=false;
        }
    }
    return dp[m][n];


}


int main(){
    int t;
    cin>>t;
    cin.ignore();
    loop(tc,1,t+1){
        string ptr,str;
        getline(cin,ptr);
        getline(cin,str);
        cout<<match(ptr,str)<<endl;    
    }
}