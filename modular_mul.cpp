#include<bits/stdc++.h> 
typedef long long ll;
using namespace std; 
ll m=1e9+7;

ll power(ll x,ll y, ll p){  
    ll res = 1;  
    x = x % p;   
    if (x == 0) return 0; 
    while (y > 0)  {  
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
} 

int main() 
{  
    
    int t;
    cin>>t;
    while(t--){
        int n,a;
        cin>>n>>a;
        ll x=a;
        ll sum=0;
        for(int i=1;i<=2*n-1;i+=2){
            sum=(sum+power(x,i,m))%m;
            x=(power(x,i,m)*(x%m))%m;
        }
        cout<<sum<<endl;

    }
	return 0; 
} 
