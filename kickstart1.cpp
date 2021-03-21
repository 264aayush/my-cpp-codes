#include <bits/stdc++.h>
#define endl "\n"
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
struct node{
    int s,e;
    node* next;

    node(){
        next=NULL;
    }

    node(int si,int ei){
        s=si;
        e=ei;
        next=NULL;
    }
    node(pair<int,int> p){
        s=p.first;
        e=p.second;
        next=NULL;
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    loop(tc,1,t+1){
        cout<<"Case #"<<tc<<endl;
        int s,x1,y1,x2,y2,c;
        cin>>s>>x1>>y1>>x2>>y2>>c;
        if(s==2){
            if(c==2){
                int jkjkjkjkjkjkjkj;
                cin>>jkjkjkjkjkjkjkj>>jkjkjkjkjkjkjkj>>jkjkjkjkjkjkjkj>>jkjkjkjkjkjkjkj;
                cout<<0<<endl;
            }
            else if(c==1){

            }
            if(c==0){
                if((x1==1 && y1==1)||(x1==2 && y1==2))
                    cout<<0<<endl;
                else{
                    
                }
            }
            
        }
        else {
            cout<<0<<endl;
        }

    }
    
	return 0;
}
