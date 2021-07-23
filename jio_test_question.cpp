#include<bits/stdc++.h>
using namespace std;


// barfoothefoofoobarmanfoofmanbarfoofoo
// 2
// foo
// foo


// barfoothefoobarmanfoofmanbarfoo
// 2
// foo
// bar

// https://www.geeksforgeeks.org/find-starting-indices-substrings-string-s-made-concatenating-words-listl/


int main(){
    string str;
    cin>>str;
    int n;
    cin>>n;
    string arr[n];
    int lengthOfAllSubstr=0;
    string concatOfAllSubstr="";
    for(int i=0;i<n;i++){
        cin>>arr[i];
        concatOfAllSubstr+=arr[i];
        lengthOfAllSubstr+=arr[i].length();
    }
    sort(concatOfAllSubstr.begin(),concatOfAllSubstr.end());
    
    for(int i=0;i+lengthOfAllSubstr-1<str.length();i++){
        string windowStr=str.substr(i,lengthOfAllSubstr);
        int found=true;
        for(int j=0;j<n;j++){
            if(windowStr.find(arr[j])!=string::npos)
                continue;
            else{
                found=false;
                break;
            }
        }
        if(found){
            sort(windowStr.begin(),windowStr.end());
            if(concatOfAllSubstr==windowStr)
                cout<<"found at: "<<i<<endl;
        }
    }

}