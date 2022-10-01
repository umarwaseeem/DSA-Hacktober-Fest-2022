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
    int n=1;
  int k=4*n;
        int arr[k+1][k+1];
        int cnt=1;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                arr[i][j]=cnt;
                cnt++;
            }
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
               cout<< arr[i][j];
            }
            cout<<endl;
        }
}
int main(){
fast_IO;
//test
solve();
return 0;
}