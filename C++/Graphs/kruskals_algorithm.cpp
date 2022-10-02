/*
	Kruskal's Algorithm to find the Minimum Spanning Tree for an undirected connected graph
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

// This function will Find Parent Vertex of the current vertex
int find_par(int v, int par[]) {
	if(par[v]==v) return v;
	return par[v] = find_par(par[v], par);
}

// This function will add Edge to MST if vertices are not joined and return true of not joined already
bool union_set(int a, int b, int par[], int ran[]) {
	a = find_par(a, par);
	b = find_par(b, par);

	// Parent will be different if they are not already joined else they are joined already
	if(a==b) return false;

	// Put the parent of low rank to high rank
	if(ran[a] < ran[b]) swap(a,b);
	par[b] = a;
	ran[a]++;
	return true;
}

// The function will return the edges required for MST using Prim's Algorithm
vector<vector<int> > kruskals(int v, vector<vector<int> > &edges) {
	// Parent Array and Rank Array
	int par[v+1], ran[v+1];
	for(int i=0;i<=v;i++) {
		par[i] = i;
		ran[i] = 1;
	}

	// Creating copy of edges and sort it based on weight of edge
	vector<vector<int> > sorted_edges;
	for(auto i: edges) {
		sorted_edges.push_back({i[2],i[0],i[1]});
	}
	sort(sorted_edges.begin(), sorted_edges.end());

	vector<vector<int> > mst;

	// Travel through all edges to select MST
	for(auto i: sorted_edges) {
		bool shouldAdd = union_set(i[1], i[2], par, ran);
		if(shouldAdd) {
			mst.push_back({i[1],i[2],i[0]});
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
	vector<vector<int> > mst = kruskals(v, edges);
	cout<<"Weight of MST Graph: "<<graphWeight(mst)<<"\n";
	cout<<"MST Graph:\n";
	printGraph(mst);
	return 0;
}