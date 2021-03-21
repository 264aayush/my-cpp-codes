#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    if(a.size()>b.size()){
        vector<int> temp=a;
        a=b;
        b=temp;
    }

    int m=a.size();
    int n=b.size();

    int imin=0,imax=m,halflen=(m+n+1)/2;

    while(imin<=imax){
        int i=(imin+imax)/2;
        int j=halflen-i;
        int minright,maxleft;
        
        if(i<imax && a[i]<b[j-1])
            imin=i+1;
        else if(i>imin && a[i-1]>b[j])
            imax=i-1;
        else{
            if(i==0)
                maxleft=b[j-1];
            else if(j==0)
                maxleft=a[i-1];
            else maxleft=max(a[i-1],b[j-1]);
            
            if( (m+n) % 2 != 0)
                return maxleft;
            
            if(i==m)
                minright=b[j];
            else if(j==n)
                minright=a[i];
            else 
                minright=min(a[i],b[j]);
            return (minright+maxleft)/2.0;

        }


    }


    return 0.0;
}
int main(){
    int t;
    cin>>t;
    loop(tc,1,t+1){
        int n,m;
        cin>>n>>m;
        vector<int> a(m),b(n);
        loop(i,0,m)
            cin>>a[i];
        loop(i,0,n)
            cin>>b[i];
        double ans=findMedianSortedArrays(a,b);
        cout<<ans<<endl;
    }
}