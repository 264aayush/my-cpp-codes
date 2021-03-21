#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

int * seg_tree;

void buildsegtree(int arr[],int low,int high,int pos=0){
    if(low==high){
        seg_tree[pos]=arr[low];
        return;
    }
    int mid=low+(high-low)/2;
    buildsegtree(arr,low,mid,2*pos+1);
    buildsegtree(arr,mid+1,high,2*pos+2);
    seg_tree[pos]=seg_tree[2*pos+1]+seg_tree[2*pos+2];
}

int getsum(int ql,int qh,int low,int high,int pos=0){
    if(ql<=low && qh>=high)
        return seg_tree[pos];
    if(high<ql||low>qh)
        return 0;
    int mid=low+(high-low)/2;
    return getsum(ql,qh,low,mid,pos*2+1)+getsum(ql,qh,mid+1,high,pos*2+2);
}
void update(int diff,int low,int high,int pos,int root=0){
    if(pos<low||pos>high)
        return;
    
    seg_tree[root]+=diff;
    int mid=low+(high-low)/2;
    if(low<high){
        update(diff,low,mid,pos,2*root+1);
        update(diff,mid+1,high,pos,2*root+2);
    }
}


void print_seg_tree(int x){
    for(int i=0;i<x;i++){
        cout<<seg_tree[i]<<" ";
    }
    cout<<endl;
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
        int seg_tree_height=ceil(log2(n))+1;
        seg_tree=new int[1<<seg_tree_height];
        buildsegtree(arr,0,n-1);
        cout<<getsum(0,3,0,4)<<endl;
        int new_val=55;
        print_seg_tree(2*n-1);
        update(new_val-arr[2],0,n-1,2);
        print_seg_tree(2*n-1);
        
    }
    
	return 0;
}