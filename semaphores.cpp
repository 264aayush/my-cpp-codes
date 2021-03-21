#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

int semaphore=1;

void process1(){

}

void process2(){

}

static void print()

int main() {
    thread t1(process1);
    thread t2(process2);



    t1.join();
    t2.join();
    
	return 0;
}
