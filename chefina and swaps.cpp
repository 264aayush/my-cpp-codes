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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n],B[n],minel=INT_MAX;
        loop(i,0,n){
            cin>>A[i];
            if(minel>A[i])
                minel=A[i];
        }
        loop(i,0,n){
            cin>>B[i];
            if(minel>B[i])
                minel=B[i];
        }

        sort(A,A+n);
        sort(B,B+n);

        int i=0,j=0;
        bool flag=false;
        
        vector<int> swapping_values_a,swapping_values_b;
        while(i<n || j<n){
            if(i<n && j<n){
                if(A[i]==B[j]){
                    i++;
                    j++;
                    continue;
                }
                else if(A[i]<B[j]){
                    if(i+1>=n){
                        flag=true;
                        break;
                    }
                    if(A[i]==A[i+1]){
                        swapping_values_a.push_back(A[i]);
                        i+=2;
                    }
                    else {
                        flag=true;
                        break;
                    }
                }
                else{
                    if(j+1>=n){
                        flag=true;
                        break;
                    }
                    if(B[j]==B[j+1]){
                        swapping_values_b.push_back(B[j]);
                        j+=2;
                    }
                    else {
                        flag=true;
                        break;
                    }
                }
            }
            else if(i==n){
                if(j+1>=n){
                    flag=true;
                    break;
                }
                if(B[j]==B[j+1]){
                    swapping_values_b.push_back(B[j]);
                    j+=2;
                }
                else {
                    flag=true;
                    break;
                }
            }else if(j==n) {//j==n
                if(i+1>=n){
                    flag=true;
                    break;
                }
                if(A[i]==A[i+1]){
                    swapping_values_a.push_back(A[i]);
                    i+=2;
                }
                else {
                    flag=true;
                    break;
                }
            }
        }
        if(flag || swapping_values_a.size()!=swapping_values_b.size()){
            cout<<-1<<endl;
            continue;
        }
        ll ans=0;
        for(i=0;i<swapping_values_b.size();i++){
            int kk=min(swapping_values_a[i],swapping_values_b[swapping_values_b.size()-1-i]);
            ans+=min(kk,minel*2);
        }
        cout<<ans<<endl;
    }
    
	return 0;
}