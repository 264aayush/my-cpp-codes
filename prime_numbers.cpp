#include<bits/stdc++.h>
using namespace std;

// bool checkprime(int n){
// 	//if(n%2==0)
// 	//	return false;
// 	//for(int i=3;i*i<=n;i+=2){
// 	//	if(n%i==0)
// 	//		return false;
// 	//}
// 	//return true;
// }
int main(){
	bool prime[1000000];
	memset(prime,true,sizeof(prime));
	prime[0]=false;
	for(int i=3;i<1000000;i++){
		for(int j=2;j*j<=i;j++){
			if(i%j==0)
				prime[(i)]=false;
		}
	}


	// vector<int> arr;
	// arr.push_back(2);
	// for(int i=3;i<1000000;i+=2){
	// 	if(checkprime(i))
	// 		arr.push_back(i);
	// }
	// //for(int i=0;i<200;i++)
	// //	cout<<arr[i]<<" ";
	// cout<<arr.size();
}