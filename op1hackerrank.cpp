#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int arr[n];
    arr[0]=1;
    long long sum=1;
    map<int,int> mp;
    mp[1]++;
    loop(i,1,n){
        arr[i]=arr[i-1]+1;
        sum+=arr[i];
        mp[arr[i]]++;    
    }
    while(m--){
        int op;
        cin>>op;
        if(mp.find(op)!=mp.end()){
            int temp=arr[0];
            arr[0]=arr[n-1];
            arr[n-1]=temp;
        }
        else{
            if(mp[arr[n-1]]==1)
                mp.erase(arr[n-1]);
            else{
                mp[arr[n-1]]--;
            }
            sum-=arr[n-1];
            arr[n-1]=op;
            sum+=op;
            mp[op]++;
        }

        cout<<sum<<endl;
    }
	return 0;
}
