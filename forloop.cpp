#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        loop(i,0,n);
            cin>>arr[i];
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                ans+=(1<<count)-1;
                count=0;    
            }
            else count++;
        }
    }
}
