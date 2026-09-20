#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2e5+2;
ll dp[N][2];
ll n,m;

bool vis[N][2];
vector<pair<ll,ll>>g[N];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        ll w;
        cin>>a>>b>>w;
        g[a].push_back({w,b});

    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 1e15;
        dp[i][1] = 1e15;
    }
    priority_queue<pair<pair<ll,ll>,ll>>q;
    dp[1][0] = 0;
    dp[1][1] = 0;
    q.push({{0,1},0});
    while(!q.empty()){
        int a = q.top().first.second;
        int s = q.top().second;
        ll wa = abs(q.top().first.first);
        q.pop();
        if(vis[a][s])continue;
        // cout<<a<<" er childs "<<wa<<":\n";
        vis[a][s] = true; 
        for(auto c:g[a]){
            int b = c.second;
            ll w = c.first;
            // cout<<b<<" a "<<w<<endl;
            // cout<<s<<endl;
            // cout<<wa<<endl;
            if(s){
                if(dp[b][1] > wa + w){
                    q.push({{-(wa + w), b},1});
                    // cout<<b<<" "<<wa+w<<" "<<a<<" "<<s<<endl;
                    dp[b][1] = wa + w;
                }
            }
            else{
                if(dp[b][1] > wa + w/2){
                    q.push({{-(wa + w/2), b},1});
                    // cout<<b<<" "<<wa+w/2<<" "<<a<<" "<<1<<endl;
                    dp[b][1] = wa + w/2;
                }
                if(dp[b][0] > wa + w){
                    q.push({{-(wa + w), b},0});
                    // cout<<b<<" "<<wa+w<<" "<<a<<" "<<s<<endl;
                    dp[b][0] = wa + w;
                }
            }
            // cout<<endl;
        }
    }
    cout<<dp[n][1]<<'\n';
    return 0;
    }