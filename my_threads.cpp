#include <iostream>
#include <thread>

using namespace std;

bool keeprunning=true;

void dowork(){
    cout<<"printing";
    while(keeprunning){
        cout<<".";
    }
}

int main() {
    thread worker(dowork);
    cin.get();
    cout<<"over";
    cin.get();
}
