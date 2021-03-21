#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

void lps(int arr[],string str){
    int n=str.length();
    int j=0;
    for(int i=1;i<n;i++){
        if(str[i]==str[j]){
            arr[i]=j+1;
            j++;
        }
        else{
            if(j>0){
                j=arr[j-1];
                i--;
            }
        }
    }
}

void kmp(string str, string ptr, int lps[]){
    int i=0,j=0;
    int n=str.length();
    int m=ptr.length();
    for(i=0;i<n;i++){
        if(j==m){
            cout<<i-m+1<<" ";
            j=lps[j-1];
            i--;
        }
        else if(str[i]==ptr[j]){
            j++;
        }
        else{
            if(j>0){
                j=lps[j-1];
                i--;
            }
        }   
    }
    if(j==m)
        cout<<n-m+1<<" ";
    
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string str,ptr;
        cin>>str>>ptr;
        int n=ptr.length();
        int pi[n];
        memset(pi,0,sizeof(pi));
        lps(pi,ptr);

        for(int i=0;i<ptr.length();i++)
            cout<<pi[i]<<" ";
        cout<<endl;
        cout<<str<<endl<<ptr<<endl;
        kmp(str,ptr,pi);
    }    
	return 0;
}