#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

void update(ll bit[],int index,ll val,int n){
	index+=1;
	while(index<=n){
		bit[index]+=val;
		index+=(index&-index);
	}
}

ll qry(ll bit[],int index){
	index+=1;
	ll sum=0;
	while(index>0){
		sum+=bit[index];
		index-=(index&-index);
	}
	return sum;
}

void printarr(int a[],int n){
	loop(i,0,n)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main() {
    int n,q;
	cin>>n>>q;
	int height[n],tastiness[n];
	loop(i,0,n)
		cin>>height[i];
	loop(i,0,n)
		cin>>tastiness[i];
	int reach_right[n];

	stack<int> s;
	loop(i,0,n){
		while(!s.empty() && height[s.top()]<=height[i]){
			reach_right[s.top()]=i-1;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()){
		reach_right[s.top()]=n-1;
		s.pop();
	}

	//printarr(reach_right,n);

	int reach_left[n];
	int rev_height[n];
	int rev_tastiness[n];

	loop(i,0,n)	rev_height[i]=height[n-1-i];
	loop(i,0,n)	rev_tastiness[i]=tastiness[n-1-i];
	
	loop(i,0,n){
		while(!s.empty() && rev_height[s.top()]<=rev_height[i]){
			reach_left[s.top()]=i-1;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()){
		reach_left[s.top()]=n-1;
		s.pop();
	}
	
	ll* bit=new ll[n+1];
	ll * rev_bit=new ll[n+1];
	memset(bit,0,sizeof(bit[0])*(n+1));
	memset(rev_bit,0,sizeof(rev_bit[0])*(n+1));
	loop(i,0,n){
		update(bit,i,tastiness[i],n);
		update(bit,reach_right[i]+1,-tastiness[i],n);
		update(rev_bit,i,rev_tastiness[i],n);
		update(rev_bit,reach_left[i]+1,-rev_tastiness[i],n);
	}

	while(q--){
		int choice;
		cin>>choice;
		if(choice==1){
			int temp,index;
			cin>>index>>temp;
			ll diff=temp-tastiness[index-1];
			tastiness[index-1]=temp;
			rev_tastiness[n-index]=temp;
			update(bit,index-1,diff,n);
			update(bit,reach_right[index-1]+1,-diff,n);
			update(rev_bit,n-index,diff,n);
			update(rev_bit,reach_left[n-index]+1,-diff,n);
		}
		else{
			int start,end;
			ll ans=0;
			cin>>start>>end;
			if(start<=end){
				start--;end--;	
				if(reach_right[start]<end){
					cout<<-1<<endl;
					continue;
				}
				ans=qry(bit,end)-qry(bit,start)+tastiness[start];
			}
			else{
				start=n-start;
				end=n-end;
				if(reach_left[start]<end){
					cout<<-1<<endl;
					continue;
				}
				ans=qry(rev_bit,end)-qry(rev_bit,start)+rev_tastiness[start];
				
			}
			cout<<ans<<endl;
		}
	}	

	


	return 0;
}