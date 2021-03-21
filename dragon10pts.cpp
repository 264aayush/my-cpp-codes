#include<iostream>
#include<bits/stdc++.h>
#define ll long 
#define mod 1000000007
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main() {
	int n,q;
	cin>>n>>q;
	ll height[n+1];
	ll tastiness[n+1];
	tastiness[0]=0;
	height[0]=0;
	for(int i=1;i<=n;i++) {
		cin>>height[i];
	}
	for(int i=1;i<=n;i++) {
		cin>>tastiness[i];
	}
	for(int i=0;i<q;i++) {
		ll x,y,z;
		cin>>x>>y>>z;
		if(x==1) {
			tastiness[y]=z;
		}
		else if(x==2) {
			ll start=y;
			ll end= z;
			ll f=end;
			ll ans=0;
			if(start==end) {
				ans= tastiness[start];
			}
			else if(height[start]<=height[end]) {
				ans= -1; 
			}
			else {
				int flag=0;
				if(start>end) {    //-ve x axis
					for(int i=end+1;i<start;i++) {
						if(height[i]>height[f] && height[i]<height[start]) {
							ans+= tastiness[i];
							f= i;
						}
						else if( height[i]>=height[start]) {
							flag=1;
							break;
						}
					}
					if(flag!=1 && start==end) {
						ans+= tastiness[start];
					}
					else if(flag!= 1 && start!=end) {
						ans+= tastiness[start];
						ans+= tastiness[end];
					}
					else if(flag==1) {
						ans= -1;
					}
				}
				else if(start<end) { // +ve x axis
					for(int i= end-1;i>start;i--) {
						if(height[i]>height[f] && height[i]<height[start]) {
							ans+= tastiness[i];
							f=i;
						}
						else if(height[i]>=height[start]) {
							flag=1;
							break;
						}
					}
					if(flag!=1 && start!= end) {
						ans+= tastiness[start];
						ans+= tastiness[end];
					}
					else if(flag!=1 && start==end) {
						ans+= tastiness[start];
					}
					else {
						ans= -1;
					}
						
				}
			}
			cout<<ans<<"\n";
		}
	}
	
 return 0;	
}

