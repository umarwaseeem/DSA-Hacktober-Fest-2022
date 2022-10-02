/*
	Prim's Algorithm to find the Minimum Spanning Tree for an undirected connected graph
*/

#include<bits/stdc++.h>

using namespace std;

// This function will return the weight of the graph
int graphWeight(vector<vector<int> > &edges) {
	int w = 0;
	for(auto i: edges) {
		w += i[2];
	}
	return w;
}

// This function will print Graph edges
void printGraph(vector<vector<int> > &edges) {
	for(auto i: edges) {
		cout<<i[0]<<" <--> "<<i[1]<<" ("<<i[2]<<")\n";
	}
	return;
}

// The function will return the edges required for MST using Prim's Algorithm
vector<vector<int> > prims(int v, vector<vector<int> > &edges) {
	// Adjacency List
	vector<vector<pair<int,int> > > adj(v+1);
	for(auto i: edges) {
		adj[i[0]].push_back({i[1],i[2]});
		adj[i[1]].push_back({i[0],i[2]});
	}

	// Mark Visited Edges
	bool vis[v+1];
	memset(vis,0,sizeof(vis));

	vector<vector<int> > mst;

	// Store Nearest Vertex to MST Graph
	priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
	pq.push({0,1,-1});
	while(pq.size()) {
		vector<int> t = pq.top();
		pq.pop();
		int d = t[0];
		int u = t[1];
		int par = t[2];

		// Skip vertices which are already added
		if(vis[u]) {
			continue;
		}
		vis[u] = true;

		// Add edges to mst graph
		if(par!=-1) {
			mst.push_back({par,u,d});
		}

		for(auto v: adj[u]) {
			if(!vis[v.first]) {
				pq.push({v.second, v.first, u});
			}
		}
	}
	return mst;
}

int main() {
	// Input Graph
	int v,e;
	vector<vector<int> > edges;
	cout<<"Vertices: ";
	cin>>v;
	cout<<"Edges: ";
	cin>>e;
	for(int i=0;i<e;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back({u,v,w});
	}

	// MST
	cout<<"Weight of Graph: "<<graphWeight(edges)<<"\n";
	vector<vector<int> > mst = prims(v, edges);
	cout<<"Weight of MST Graph: "<<graphWeight(mst)<<"\n";
	cout<<"MST Graph:\n";
	printGraph(mst);
	return 0;
}