#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int main() {
    int n;
    cin>>n;
    pair<int,int> arr[n];

    loop(i,0,n){
        cin>>arr[i].first;
        arr[i].second=i;    
    }

    sort(arr,arr+n,comp);
    bool recur=false;
    int ans=INT_MAX;
    for(int i=1;i<n;i++){
        if(arr[i].first==arr[i-1].first){
            recur=true;
            ans=min(ans,arr[i].second);
        }
    }
    if(!recur)
        cout<<-1<<endl;
    else cout<<ans<<endl;


	return 0;
}
