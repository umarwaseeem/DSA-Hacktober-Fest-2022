#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+1;
vector<int> ar[N];
vector<int> tr[N];
vector<int> order; // to maintain order of out time
vector<int> SCC;// to store SCC
int vis[N];
void dfs(int node)
{
    vis[node] = 1;
    for(int child : ar[node])
    {
        if(vis[child]==0)
        {
            dfs(child);

        }
    }
    order.push_back(node);
}
void dfs1(int node)
{
    vis[node] = 1;
    for(int child : tr[node])
    {
        if(vis[child]==0) dfs1(child);
    }
    SCC.push_back(node);
}
int main()
{
    int n,a,b,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0 ; i<n ; i++) ar[i].clear() , tr[i].clear() , vis[i]=0;
        order.clear();
        for(int i=0 ; i<m ; i++)
        {
            cin>>a>>b;
            ar[a].push_back(b);
            tr[b].push_back(a); // constructing transverse graph
        }
        for(int i=0 ; i<n ;i++)
        {
            if(vis[i]==0) dfs(i); // initializing out time
        }
        for(int i=0 ; i<n ; i++) vis[i] = 0; // reseting visited so as to use it in next dfs call
        for(int i=0 ; i<n ; i++)
        {
            if(vis[order[n-i]]==0)
            {
                SCC.clear();
                dfs1(order[n-i]);
                cout<<"dfs1() called from"<<order[n-i]<<" and printing SCC\n";
                for(int node : SCC)
                {
                    cout<<node<<" ";
                    cout<<endl;
                }
            }
        }
    }
}
// condensation graph being used