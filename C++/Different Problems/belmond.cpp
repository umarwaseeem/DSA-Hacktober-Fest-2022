#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define endl '\n' 
#define setbits   __builtin_popcountll
#define msort(v)  sort((v).begin(),(v).end())
#define all(c)  (c).begin(), (c).end()
#define fill(container, value)  memset((container), (value), sizeof(container))
#define test ll t; cin >> t; while (t--)
#define fast_IO    ios_base::sync_with_stdio(false);    cin.tie(NULL);
void solve(){
 ll n,m,u,v,wt,src;
 cin >> n >> m ;

 vector<vector<ll>>adj;
 vector<int>dis(n,INT_MAX);

  for(int i=0;i<m;i++){
     cin>>u>>v,wt;
     adj.push_back({u,v,wt});
 }
 cin>>src;
 dis[src]=0;
 int k=n-1;
 dis[0]=0;
 while(k--){
   for(auto it:adj){
     if(dis[it[0]]+it[2]<dis[it[1]]){
        dis[it[1]]=dis[it[0]]+it[2];
     }
   }
 }
 for(auto it:adj){
    if(dis[it[0]+it[2]<dis[it[1]]]){
        cout<<"NEGATIVE CYCLE"<<endl;
        return ;
    }
 }

 for(int i=0;i<n;i++){
    cout<<dis[i]<<endl;
 }
}
int main(){
fast_IO;
test
solve();
return 0;
}