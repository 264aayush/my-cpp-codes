#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        int n,k;
        cin>>n>>k;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        map<int,int,greater<int>> mp;
        for(int i=0;i<n-1;i++)
            mp[arr[i+1]-arr[i]]++;
        auto front=*mp.begin();
        while(front.second<=k){
            
        }





        //cout<<"Case #"<<tc<<": "<<front.first()<<endl;
    }
}