#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<int>> combine(int n, int k)
{
    vector<int> arr(k);
    for (int i = 0; i < k; i++)
    {
        arr[i] = n - i;
    }
    vector<vector<int>> ret_val;
    ret_val.push_back(arr);
    int index = k - 1;
    while (arr[0] >= k)
    {
        
        if (arr[index] > 1)
        {
            arr[index]--;
            ret_val.push_back(arr);
            continue;
        }
        else
        {
            while (index >= 0 && arr[index] == k - index)
                index--;
            if (index == -1)
                break;
            arr[index]--;
            index++;
            for (; index < k; index++)
                arr[index] = arr[index - 1] - 1;
            index--;
            arr[index]++;
        }
    }
    return ret_val;
}

int main(){
    int n,k;
    cin>>n>>k;
    auto arr=combine(4,2);

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++)
            cout<<arr[i][j];
        cout<<endl;
    }
    
}