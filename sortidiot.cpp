#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int holding=-1;
        bool trans=false;
        int ans=0;
        for(int i=0;i<prices.size()-1;i++){
            if(!trans && prices[i]<prices[i+1]){
                holding=prices[i];
                trans=true;
            }
            else if(trans && prices[i]<prices[i+1]){
                ans+=holding-prices[i];
                trans=false;
            }
        }
        if(trans){
            ans+=holding-prices[prices.size()-1];
        }
        return ans;
    }
};