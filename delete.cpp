#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<4;i++)
        cin>>arr[i];
    int count[n][26];
    memset(count,0,sizeof(count));
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++)
            cout<<count[i][j];
    }
}