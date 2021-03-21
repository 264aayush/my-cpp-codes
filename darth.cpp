#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        vector<int> strip;
        for(int i=0;i<n;i++){
            int start=i,end=i;
            bool flag=false;
            while(end<n && arr[end]==0){
                flag=true;
                end++;
            }
            if(flag){
                strip.push_back(end-start);
                i=end-1;
            }
        }
        sort(strip.begin(),strip.end());
        if(strip.size()==0)
            cout<<"No\n";
        else if(strip.size()==1){
            if(strip[0]%2==0)
                cout<<"No\n";
            else cout<<"Yes\n";
            continue;
        }else{
            int max_strip=strip[strip.size()-1];
            if(max_strip==1||max_strip%2==0){
                cout<<"No\n";
                continue;
            }
            else{
                int max2_strip=strip[strip.size()-2];
                if(max2_strip>=ceil((float)max_strip/2))
                    cout<<"No\n";
                else cout<<"Yes\n";
            }
        }
    }

}
