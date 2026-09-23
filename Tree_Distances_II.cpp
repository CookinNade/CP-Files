#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 2e5+2;
vector<int>g[N];
ll dist[N];
int p[N];
ll ans[N];
ll sub[N];
int upor[N];
void dfs(int v){
    for(auto c:g[v]){
        if(c == 1 or p[c])continue;
        p[c] = v;
        dfs(c);
    }
}
int n;
void yo(int v){
    for(auto c:g[v]){
        if(c == p[v])continue;
        ll add = ans[v] - sub[c] - dist[c] - 1;
        add = add + n - sub[c] - 1;
        add = add + dist[c];
        ans[c] = add;
        yo(c);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int cnt[n+1];
    fill(cnt,cnt+1+n,0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    queue<int>q;
    for(int i=2;i<=n;i++){
        if(cnt[i] == 1)q.push(i);
    }
    
    dfs(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        // cout<<v<<endl;
        int par = p[v];
        cnt[par]--;
        if(cnt[par] == 1)q.push(par);
        dist[par] = dist[par] + dist[v] + sub[v] + 1;
        sub[par] = sub[par] + sub[v] + 1;

    }
    
    ans[1] = dist[1];
    yo(1);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
    }