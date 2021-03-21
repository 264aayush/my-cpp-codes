#include<bits/stdc++.h>
using namespace std;

void updatebit(int * bit,int n, int i, int val){
	i=i+1;
	while(i<=n){
		bit[i]+=val;
		i+=(i&(-i));
	}

}



int * constructBIT(int *arr,int n){
	int * ret_val=new int[n+1];								//ret_val in binary indexed tree
	memset(ret_val,0,(n+1)*sizeof(ret_val[0]));
	for(int i=0;i<n;i++){
		updatebit(ret_val,n,i,arr[i]);
	}
	return ret_val;
}

int getsum(int * bit,int index){
	int sum=0;
	index+=1;
	while(index>0){
		sum+=bit[index];
		index-=(index&(-index));	
	}
	return sum;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	int *bit=constructBIT(arr,n);
	for(int i=1;i<n+1;i++)
		cout<<bit[i]<<" ";


}