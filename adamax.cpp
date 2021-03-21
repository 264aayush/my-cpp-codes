#include <bits/stdc++.h>
#define endl "\n"
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll sum=(n*(n+1))/2;
        if(sum%2!=0){
            cout<<0<<endl;
            continue;
        }
        sum/=2;
        long long start=bs(1,n,sum-(n-1));
        ll end=bs(1,n,sum);
        while(sum<(end*(end+1))/2){
            end--;
        }
        ll ans=0;
        for(ll i=start;i<=end;i++){
            ll left_sum=(i*(i+1))/2;
            int diff=sum-left_sum;
            int pos_start=1;
            int pos_end=1+diff;
            if(pos_end<=i){
                pos_end=i+1;
                pos_start=pos_end-diff;
            }
            ans+=1+min(i-pos_start,n-pos_end);
            if(diff==0){
                ans+=(i*(i-1))/2;
                ans+=((n-i)*((n-i)-1))/2;
            }
        }
        cout<<ans<<endl;
    }
    
	return 0;
}
