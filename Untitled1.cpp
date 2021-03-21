#include <bits/stdc++.h>
#define loop(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;
using namespace std;

string bin_rep(int n){
	string s="";
	for(int i=0;i<32;i++){
		if(((1<<i)&n)!=0)
			s.push_back('1');
		else s.push_back('0');
	}
	reverse(s.begin(),s.end());
	return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t; 
    while(t--){
    	int n,q;
    	cin>>n>>q;
    	int arr[n];
    	for(int i =0;i<n;i++){
    		cin>>arr[i];
    	}
    	int x1[q],x2[q],y[q];
    	for(int i=0;i<q;i++)
			cin>>x1[i]>>x2[i]>>y[i];							
		
    }
	return 0;
}
