// for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++)
//         cout<<dp[i][j]<<"\t";
//     cout<<endl;
// }

// if((216-t-1)%6==0)
//     cout<<endl;

// for(int i=0;i<n;i++)
//     cout<<arr[i]<<" ";
// cout<<":      ";
#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

int count(int infected[],int n){
    int ans=0;
    for(int i=0;i<n;i++){
        if(infected[i]!=-1)
            ans++;
    }
    return ans;
}

void solve(int arr[10],int dp[10][10],int infected[10],int i,int t,int n){
    if(infected[i]==-1)
        return;
    for(int j=0;j<n;j++){
        if(dp[i][j]==-1||infected[i]>dp[i][j]||i==j)
            continue;
        int temp;
        if(arr[i]==0)
            temp=(dp[i][j]-j)/arr[j];
        else temp=(dp[i][j]-i)/arr[i];
        if(temp<t)
            return;
        infected[j]=dp[i][j];
        solve(arr,dp,infected,j,t+temp,n);
    }
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[10];
        loop(i,0,n)
            cin>>arr[i];
        int dp[10][10];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]>=arr[i]||arr[i]==0)
                    continue;
                int dist=j-i;
                int cover_ability_per_sec=arr[i]-arr[j];
                if(dist%cover_ability_per_sec==0){
                    dp[i][j]=((arr[i]*dist)/cover_ability_per_sec)+i;
                }
            }
            for(int j=0;j<i;j++){
                if(arr[j]<=arr[i]||arr[j]==0)
                    continue;
                int dist=i-j;
                int cover_ability_per_sec=arr[j]-arr[i];
                if(dist%cover_ability_per_sec==0){
                    dp[i][j]=((arr[i]*dist)/cover_ability_per_sec)+i;
                }
            }
        }



        int infected[10];
        int worst=0;
        int best=n;
        for(int i=0;i<n;i++){
            memset(infected,-1,sizeof(infected));
            infected[i]=i;
            solve(arr,dp,infected,i,0,n);
            worst=max(count(infected,n),worst);
            best=min(best,count(infected,n));
        }
        cout<<best<<" "<<worst<<endl;
        
    }
    
	return 0;
}

