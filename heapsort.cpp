#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

using namespace std;


void heapify(int arr[], int n, int i){
    int l=2*i+1;
    int r=2*i+2;

    int largest=i;

    if(l<n && arr[largest]<arr[l]){
        largest=l;
    }
    if(r<n && arr[largest]<arr[r]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[],int n){
    for(int i=n/2;i>=0;i--){
        heapify(arr,n,i);
    }

    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        loop(i,0,n)
            cin>>arr[i];
        heapsort(arr,n);
        loop(i,0,n)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    
	return 0;
}
