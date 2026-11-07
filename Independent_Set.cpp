#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+2;
const ll M = 1e9+7;
vector<int>g[N];
ll dp[N][2];
int n;
ll dfs(int v, int p, int b){
    if(g[v].size() == 1 and v!=1)return 1;
    if(dp[v][b]!=-1)return dp[v][b];
    ll way = 1;
    for(auto c:g[v]){
        if(c == p)continue;
        if(b){
            ll mul = dfs(c,v,0) % M;
            way = (way * mul) % M;
        }
        else{
            ll mul1 = dfs(c,v,1) % M;
            ll mul2 = dfs(c,v,0) % M;
            ll mul = (mul1 + mul2) % M;
            way = (way * mul) % M;
        }
    }
    return dp[v][b] = way % M;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    memset(dp,-1,sizeof dp);
    if(n == 1){
        cout<<2;
        return 0;
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout<<(dfs(1,-1,0) + dfs(1,-1,1)) % M;
    return 0;
    }