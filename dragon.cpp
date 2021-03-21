#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define vec vector<int>
#define maxh priority_queue<int>
#define minh priority_queue<int,vec,greter<int> >
#define wer(i,a,b) for(int i=a;i<b;i++)
#define test int _; cin>>_; while(_--)
#define sortarr sort(arr, arr+n)
#define mod 1000000007
#define endl "\n"

void updateBIT(int arr[], int n, int index, int val) {
    index++; 
    while (index <= n) {
        arr[index] += val; 
        index += index & (-index); 
    } 
} 

int *buildTree(int n) {
    int *BITree = new int[n+1]; 
    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 
    return BITree; 
} 

int query(int BITree[], int index) {
    int sum = 0;
    index++; 
    while (index>0) {
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 

void change(int *BITree, int l, int r, int n, int val) {
    updateBIT(BITree,n,l,val);
    updateBIT(BITree,n,r,-val);
}

int32_t main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q; cin>>n>>q;
    int *bt  = buildTree(n);
    int *bt1 = buildTree(n);
    int h[n], arr[n], h1[n], arr1[n];
    wer(i,0,n) cin>>h[i];
    wer(i,0,n) cin>>arr[i];
    wer(i,0,n) h1[i]=h[n-1-i];
    wer(i,0,n) arr1[i]=arr[n-1-i];
    int B[n],B1[n];
    
    stack<int> s;
    wer(i,0,n) {
        while(!s.empty() && h[s.top()] <= h[i]) {
            B[s.top()] = i-1;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) {
        B[s.top()] = n-1;
        s.pop();
    }

    wer(i,0,n) {
        while(!s.empty() && h1[s.top()] <= h1[i]) {
            B1[s.top()] = i-1;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) {
        B1[s.top()] = n-1;
        s.pop();
    }

    
    
    wer(i,0,n) change(bt,i+1,B[i]+1,n,arr[i]);
    wer(i,0,n) change(bt1,i+1,B1[i]+1,n,arr1[i]);    
    
    
    while(q--) {
        int x,y,z; cin>>x>>y>>z;
        
        if(x==2) {
            if(y<=z) {
                if(z-1 > B[y-1]) cout<<-1<<endl;
                else             cout<< query(bt,z-1)-query(bt,y-1)+arr[z-1] <<endl; 
            }
            else {
                if(n-z > B1[n-y]) cout<<-1<<endl;
                else              cout<< query(bt1,n-z)-query(bt1,n-y)+arr1[n-z] <<endl; 
            }
        }
        
        else {
            change(bt,y,B[y-1]+1,n,z-arr[y-1]);
            arr[y-1]=z;
            change(bt1,n-y+1,B1[n-y]+1,n,z-arr1[n-y]);
            arr1[n-y]=z;
        }
        
    }   
}
