#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

int cureall(int A,ll x){
    int count=1;
    while(x<A){
        x*=2;
        count++;
    }
    return count;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        long long x;
        cin>>n>>x;
        int arr[n];
        loop(i,0,n)
            cin>>arr[i];
        sort(arr,arr+n);
        int days=0;
        ll cures=x;
        for(int i=0;i<n;i++){
            if(cures>=arr[i]){
                days++;
                if(cures<arr[i]*2)
                    cures=arr[i]*2;
            }
            else if(arr[i]%2==0){
                days+=cureall(arr[i],cures);
                cures=arr[i]*2;
            }
            else{
                days+=cureall(arr[i],cures);
                cures=(arr[i]-1)*2;
            }  
        }
        cout<<days<<endl;
    }
    
	return 0;
}
