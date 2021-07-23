#include <bits/stdc++.h>
#define endl "\n"
#define loop(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
using namespace std;

inline int intscan()
{
  char ch = getchar();
  bool neg = false;
  while (ch < '0' || ch > '9')
  {
    if (ch == '-')
      neg = true;
    ch = getchar();
  }
  int x = 0;
  while (ch >= '0' && ch <= '9')
  {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  if (neg)
    return -1 * x;
  return x;
}

inline void printint(int x)
{
  char str[20];
  if (x < 0)
  {
    putchar('-');
    x = x * -1;
  }
  int i = 0;
  do
  {
    str[i++] = (x % 10) + '0';
    x = x / 10;
  } while (x > 0);
  i--;
  while (i > -1)
    putchar(str[i--]);
}

class Graph
{
  int V;
  vector<int> *adj;

public:
  Graph() {}
  Graph(int v)
  {
    V = v;
    adj = new vector<int>[V];
  }
  void addedge(int u, int v)
  {
    adj[u].push_back(v);
  }
};


bool isDecending(string s){
  for(int i=0;i<s.length()-1;i++){
    if(s[i]<s[i+1])
      return false;
  }
  return true;
}

int findGreaterThan(string s,int index){
  char temp=s[index];
  int n=s.length();
  char ans=-1;
  for(int i=index+1;i<n;i++){
    if(s[i]>temp && ans==-1)
      ans=i;
    else if(s[i]>temp && s[ans]>s[i])
      ans=i;
  }
  return ans;
}

void swap(string &s,int i,int j){
  char temp=s[i];
  s[i]=s[j];
  s[j]=temp;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    if (isDecending(s))
    {
      cout <<"not possible"<<endl;
      continue;
    }
    int n = s.length();
    int i=n-2;
    while(i>=0){
      if(s[i]<s[i+1]){
        int index=findGreaterThan(s,i);
        // cout<<index<<endl;
        swap(s,i,index);
        cout<<s<<endl;
        sort(s.begin()+i+1,s.end());
        cout<<s<<endl;
        break;
      }
      i--;
    }
  
  
  }

  return 0;
}
