#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

int fun(int arr[],int n,int x){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(arr[i]^x);
    }
    return sum;
}


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<21;i++)
        cout<<fun(arr,n,(1<<i)-1)<<endl;

    for(int i=1;i<n;i++)
        arr[0]^=arr[i];
    cout<<arr[0]<<endl;
}
