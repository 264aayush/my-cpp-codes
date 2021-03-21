#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int bit[n+1];
	memset(bit,0,(n+1)*sizeof(bit[0]));
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cout<<x<<" ";
		int index=i;
		while(index<=n){
			bit[index]+=x;
			index+=(index&(-index));
		}

	}
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<bit[i]<<" ";

}