#include <bits/stdc++.h>
using namespace std;

const long long INF = 2e18;

int N;
long long ans;
vector<vector<int>> graph;
vector<int> parity, color, excess, req;

// below function assign parity to the node, NOTE, tree is a bipartite graph.
void assignParity(int node, int parent, int t) {
	parity[node] = t;
	for(auto to : graph[node]) {
		if(to == parent) continue;
		assignParity(to, node, t^1);
	}
}

void dfs(int node, int parent, int prty) {
	excess[node] = (parity[node] == prty);
	req[node] = (color[node] == 0);
	for(auto child : graph[node]) {
		if(child == parent) continue;
		dfs(child, node, prty);
		excess[node] += excess[child];
		req[node] += req[child];
	}
	int temp = min(excess[node], req[node]);
	excess[node] -= temp;
	req[node] -= temp;
	ans += excess[node] + req[node]; // if the number of unsatisfied nodes is non-zero then it will contribute to our answer by swapping along the edge (node --- parent).
	// exiting process of the dfs can be visualized as moving up an edge(node --- parent)
}

void solveTestCase() {
	cin >> N;
	graph.clear();
	graph.resize(N+1);
	parity.assign(N+1, 0);
	color.assign(N+1, 0);
	excess.assign(N+1, 0);
	req.assign(N+1, 0);
	for(int i = 0; i < N-1; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 1; i <= N; i ++) {
		char in; cin >> in;
		color[i] = (in-'0'); // let 0 be red color and 1 be blue color.
	}
	assignParity(1, -1, 0); // we will root the tree at node 1.
	long long res = INF;
	for(int i = 0; i < 2; i ++) {
		ans = 0;
		dfs(1, -1, i); // trying to assign color 0 to nodes with parity i, in minimum number of steps. 
		if(excess[1] == req[1]) { // If we have successfully assigned the nodes.
			res = min(ans, res);
		}
	}
	if(res == INF) cout << -1 << endl;
	else cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int testCase;
	cin >> testCase;
	for(int i = 1; i <= testCase; i ++) {
		solveTestCase();
	}

	return 0;
}