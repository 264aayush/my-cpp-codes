#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

ll temp;
int cureall(int A,ll x){
    cout<<"cureall("<<A<<","<<x<<")";

    int count=1;
    bool run=false;
    while(x<A){
        x*=2;
        run=true;
        count++;
    }
    if(!run){
        temp=A;
    }
    else {
        temp=A;
        if(temp>1 && temp%2!=0)
            temp--;
    }
    cout<<" = "<< count<<", temp = "<<temp<<endl;
    return count;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        long long x;
        cin>>n>>x;
        int arr[n];
        loop(i,0,n)
            cin>>arr[i];
        sort(arr,arr+n);
        // if(x>=arr[n-1]){
        //     cout<<n<<endl;
        //     continue;
        // }
        int days[n];
        for(int i=0;i<n;i++){
            days[i]=cureall(arr[i],x)+i;
        }
        int valx[n];
        if(arr[0]%2==0||arr[0]==1||arr[0]<=x)
            valx[0]=arr[0];
        else 
            valx[0]=arr[0]-1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                ll val=valx[j];
                bool set_valx=false;
                int kk=cureall(arr[i],val*2);
                if(days[i]>days[j]+kk+i-j-1){
                    days[i]=days[j]+kk+i-j-1;
                    valx[i]=temp;
                    set_valx=true;
                }
                if(!set_valx){
                    valx[i]=arr[i];
                    if(valx[i]%2!=0 && valx[i]>x)
                        valx[i]--;
                }
            }
            

        }
        loop(i,0,n)
            cout<<days[i]<<" ";
        cout<<endl;

        // cout<<days[n-1]<<endl;


        
    }
    
	return 0;
}
