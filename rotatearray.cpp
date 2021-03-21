#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;


vector<vector<int>> rot(vector<int> a,vector<int> b){
    vector<vector<int>> ans;
    vector<int> temp;
    int m=a.size(),n=b.size();

    for(int i=0;i<n;i++){
        
        temp.clear();
        b[i]%=m;
        for(int j=b[i];j<m;j++)
            temp.push_back(a[j]);
        for(int j=0;j<=b[i]-1;j++)
            temp.push_back(a[j]);
        ans.push_back(temp);
    }

    return ans;

}


int main(){

    int n,m;
    cin>>m>>n;
    vector<int> a(m),b(n);
    loop(i,0,m)
        cin>>a[i];
    loop(i,0,n)
        cin>>b[i];
    vector<vector<int>> x= rot(a,b);

    loop(i,0,x.size()){
        loop(j,0,m)
            cout<<x[i][j]<<" ";
        cout<<endl;
    }





}