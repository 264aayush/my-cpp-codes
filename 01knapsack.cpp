#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;



int knapsack(int W,int wt[],int val[],int n){
    if(n==0)
        return 0;
    if(wt[n-1]>W)
        return knapsack(W,wt,val,n-1);
    int dont_consider=knapsack(W,wt,val,n-1);
    int consider=knapsack(W-wt[n-1],wt,val,n-1)+val[n-1];

    return max(consider,dont_consider);
}


int main() 
{ 
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout << knapsack(W, wt, val, n); 
    return 0; 
} 