#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;


inline void printint(int x){
    char str[20];
    if(x<0){
        putchar('-');
        x=x*-1;
    }
    int i=0;
    do{
        str[i++]=(x%10)+'0';
        x=x/10;
    }while(x>0);
    i--;
    while(i>-1)
        putchar(str[i--]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k,m;
        cin>>n>>m>>k;
        int scores[k];
        memset(scores,0,sizeof(scores));
        for(int i=0;i<n;i++){
            
            int min_score_index=0;
            
            for(int j=0;j<k;j++){
                if(scores[min_score_index]>scores[j]){
                    min_score_index=j;
                }
            }
            
            int quesi_ans[k];

            for(int j=0;j<k;j++)
                cin>>quesi_ans[j];

            int count_instances[m];
            memset(count_instances,0,sizeof(count_instances));
            loop(j,0,k){
                if(scores[j]==scores[min_score_index])
                    count_instances[quesi_ans[j]-1]++;
            }
            
            int ans=1;

            int kk=0;
            loop(j,0,m){
                if(count_instances[kk]<count_instances[j])
                    kk=j;
            }    
            ans=kk+1;
            loop(j,0,k){
                if(quesi_ans[j]==ans){
                    scores[j]++;
                }
            }
            cout<<ans<<endl;
        }
    }
}
