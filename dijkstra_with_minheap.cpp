#include <bits/stdc++.h>
#define endl "\n"
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;

struct comp{
    bool operator() (pair<int,int> a,pair<int,int> b){
        if(a.second==b.second){
            return a.first>b.first;
        }
        return a.second>b.second;
    }
};


int dijkstra(vector<pair<int,int>> graph[],int n,int source,int dest){
    if(source==dest)
        return 0;
    int dist[n];
    bool vis[n];
    for(int i=0;i<n;i++)
        dist[i]=INT_MAX;
    memset(vis,false,sizeof(vis));
    dist[source]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> heap;
    heap.push({source,0});
    while(!heap.empty()){
        auto u=heap.top();
        heap.pop();
        if(vis[u.first]||dist[u.first]<u.second)
            continue;
        vis[u.first]=true;
        for(auto edge:graph[u.first]){
            if(vis[edge.first])
                continue;
            if(dist[edge.first]==INT_MAX||dist[edge.first]>dist[u.first]+edge.second){
                dist[edge.first]=dist[u.first]+edge.second;
                heap.push({edge.first,dist[edge.first]});
            }
        }
    }
    return dist[dest];
}


int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> graph[n];
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        graph[u].push_back({v,weight});
    }
    int source,dest;
    cin>>source>>dest;
    cout<<dijkstra(graph,n,source,dest);
    
	return 0;
}
