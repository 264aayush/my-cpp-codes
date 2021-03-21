#include <iostream>
#include <thread>
using namespace std;

bool keeprunning=true;

void shout(int n,int j){
    n=1;
    cout<<n<<endl;
    cout<<j<<endl;
    while(keeprunning){    
        cout<<n<<endl;
        _sleep(1500UL);
    }
}

void shutup(int n,int j){
    n=2;
    cout<<n<<endl;
    cout<<j<<endl;
    while(keeprunning){
        cout<<n<<endl;
        _sleep(1500UL);
    }
}



int main() {
    thread th(shout,1,6);
    thread t(shutup,2,4);
    cin.get();
    keeprunning=false;

    th.join();
    t.join();


    cout<<"\nthe end\n";
    
	return 0;
}
