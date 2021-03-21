#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

class car{
    string brand;
    string model;
    public:
    car(string a,string b){
        brand=a;
        model=b;
    }
    bool operator==(car x){
        if(x.brand==brand){
            cout<<model<<endl;
            return true;
        }
        else return false;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    
    car a("maruti","swift"),b("honda","wrv"),c("maruti","wagonR");
    if(a==b)
        cout<<"equal"<<endl;
    else 
        cout<<"not equal"<<endl;
    if(a==c)
        cout<<"equal"<<endl;
    else 
        cout<<"not equal"<<endl;
}
