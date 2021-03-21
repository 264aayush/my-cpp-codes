#include <bits/stdc++.h>
#define endl "\n"
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

bool comp(int a,int b){
    return a>b;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        loop(i,0,n)
            cin>>arr[i];
        sort(arr,arr+n,comp);
        int count=0,prev=-1;

        for(int i=0;i<n;i++){
            if(arr[i]==0)
                break;
            if(arr[i]!=prev){
                count++;
                prev=arr[i];
            }
        }
        cout<<count<<endl;
    }
    
	return 0;
}
