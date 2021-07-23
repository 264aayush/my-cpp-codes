#include <bits/stdc++.h>
#define endl "\n"
#define loop(i, a, b) for (int i = a; i < b; i++)
typedef long long ll;
using namespace std;

int arr[500][500];
int st[500][500];

int find_max_side(int a, int b, int m, int n)
{
	if (arr[a][b] == 0)
		return 0;
	int side = min(m - a, m - b);
	for (int i = a; i < a + side; i++)
	{
		for (int j = b; j < b + side; j++)
		{
			if (arr[i][j] == 0)
				side = max(i - a, j - b);
		}
	}
	return side;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		memset(st,0,sizeof(st));
		for(int j=0;j<n;j++)
			st[0][j]=arr[0][j];
		for(int i=0;i<n;i++)
			st[i][0]=arr[i][0];
		int ans=0;
		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				if(arr[i][j]==0){
					st[i][j]=0;
					continue;
				}
				st[i][j]=min(st[i-1][j-1],min(st[i][j-1],st[i-1][j]))+1;
				ans=max(ans,st[i][j]);
			}
		}		
		cout<<ans<<endl;
	}

	return 0;
}
