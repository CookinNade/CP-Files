#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 35;
ll dp[N][N];
ll n,k;
ll bs(ll i, ll b){
    if(i==n+1 and b == k)return 1ll;
    if(dp[i][b]!=-1)return dp[i][b];

    ll ways = 0;
    ll baki = k-b;
    ll col = n-i+1;
    // cout<<i<<" i and b "<<b<<'\n';
    // cout<<col<<" col and baki "<<baki<<'\n';
    if(col > baki)
    ways = bs(i+1,b);
    ways = ways + (n-b) * (bs(i+1,b+1));
    return dp[i][b] = ways;

}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,cnt; 
    // cout<<nCk(4,2)<<'\n';
    // cout<<nPk(30,29)<<'\n';
    cin>>t;
    int tt = 1;
    while (t--){
        cout<<"Case "<<tt++<<": ";
        cin>>n>>k;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++)dp[i][j] = -1;
        }
        cout<<bs(1,0)<<'\n';
        
    }
    return 0;
    }