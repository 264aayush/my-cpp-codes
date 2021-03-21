
//return sum of a given range query

#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

struct query{
    int l,r,pos;
};
int blocks;

bool comp(query a,query b){
    if(a.l/blocks!=b.l/blocks)
        return a.l<b.l;
    return a.r<b.r;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        blocks=(int) sqrt(n);
        int arr[n];
        loop(i,0,n)
            cin>>arr[i];
        int q;
        cin>>q;
        query qarr[q];
        loop(i,0,q){
            cin>>qarr[i].l>>qarr[i].r;
            qarr[i].pos=i;    
        }
        sort(qarr,qarr+q,comp);
        int sum=0;
        int ans[q];
        int currL=qarr[0].l,currR=qarr[0].r;
        loop(i,currL,currR+1)
            sum+=arr[i];
        ans[qarr[0].pos]=sum;
        for(query i:qarr){
            while(i.l<currL){
                sum+=arr[--currL];
            }
            while(i.l>currL){
                sum-=arr[currL++];
            }
            while(i.r>currR)
                sum+=arr[++currR];
            while(i.r<currR)
                sum-=arr[currR--];
            
            ans[i.pos]=sum;

            
        }
        for(auto i:ans)
            cout<<i<<" ";
        cout<<endl;
    }
}