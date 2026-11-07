#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
/* ki ki lagbe
parents list dfs done
best list kahn algo done

*/
int n;
map<ll, ll> mp;
const int N = 1e5 + 2;
int parent[N];
int root;
int sz[N];
ll best[N];
ll child[N];
ll upore[N];
vector<int> g[N];
const ll INF = 1e16;
void par(int v, int p) {
    for (auto c : g[v]) {
        if (c == p) continue;
        parent[c] = v;
        par(c, v);
    }
}
ll dfs(int v, int oito){
    // cout<<"works here  "<<v<<" "<<oito<<endl;
    ll ans = INF;
    if(oito == root){

        auto it = mp.lower_bound((int)g[oito].size()-1);
        if(it != mp.end()) upore[v] = child[oito] - best[v] + (*it).second ; 
        it = mp.lower_bound(n-sz[v]-1);
        if (it!=mp.end()) upore[v] = min(upore[v], (*it).second);
        it = mp.lower_bound(g[v].size());
        if(it!=mp.end())ans = upore[v] + child[v] + (*it).second; 
        
    }
    else{
        auto it = mp.lower_bound((int)g[oito].size() - 1);
        if(it!=mp.end()) upore[v] = upore[oito] + (*it).second + child[oito] - best[v];
        it = mp.lower_bound(n-sz[v]-1);
        if (it!=mp.end()) upore[v] = min(upore[v], (*it).second);
        it = mp.lower_bound(g[v].size());
        if(it!=mp.end()) ans = upore[v] + child[v] + (*it).second; 
    }
    for(auto c:g[v]) if(c!=oito) ans = min(ans, dfs(c,v));
    // cout<<ans<<" yo "<<v<<endl;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin>>m>>n; 

        mp.clear();
        fill(sz + 1, sz + 1 + n, 0);
        fill(best + 1, best + 1 + n, 0);
        fill(child + 1, child + 1 + n, 0);
        fill(upore + 1, upore + 1 + n, INF);
        for(int i=1;i<=n;i++)g[i].clear();
        
        
        int cnt[n + 1]; pair<ll, ll> p[m];
        for (int i = 0; i < m; i++) cin >> p[i].first;
        for (int i = 0; i < m; i++) cin >> p[i].second;
        sort(p, p + m);
        ll curp = INF;
        for (int i = m - 1; i >= 0; i--) {
            if (curp > p[i].second) {
                curp = p[i].second;
                mp[p[i].first] = curp;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int mx = 0;

        for (int i = 1; i <= n; i++) mx = max((int)g[i].size(), mx);

        // cout<<mx<<endl;
        if(n == 1){
            auto it = mp.lower_bound(1);
            cout<<(*it).second<<'\n';
            continue;
        }
        if (p[m - 1].first < mx - 1) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if ((int)g[i].size() == 1) {
                root = i;
                break;
            }
        }

        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if((int)g[i].size() == 1 and root!=i) q.push(i);
        }
        for (int i = 0; i <= n; i++)cnt[i] = (int)g[i].size();
        
        parent[root] = 0;
        par(root, 0);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cnt[parent[v]]--;
            if (cnt[parent[v]] == 1) q.push(parent[v]);
            // cout<<v<<" these have gone in\n";
            sz[parent[v]] += sz[v] + 1;
            auto it = mp.lower_bound(sz[v] + 1);
            auto nit = mp.lower_bound((int)g[v].size() - 1);
            child[v] = best[v];
            best[v] = best[v] + (*nit).second;
            if(it!=mp.end()) best[v] = min(best[v], (*it).second);
            best[parent[v]] += best[v];
            if(q.empty() and v!= root) q.push(root);
        }

        auto it = mp.lower_bound(n);
        ll ans = 1e15;

        if(best[root]!=0)ans = best[root];
        if(it!=mp.end()) ans = min(ans, (*it).second);
        ans = min(ans, dfs(g[root][0], root));
        
        // cout<<"this is root "<<root<<endl;
        // cout<<best[root]<<" this is best [root]\n"<<endl;
        // for(int i=1;i<=n;i++)cout<<i<<" "<<sz[i]<<" "<<best[i]<<" "<<parent[i]<<endl;

        if(ans>=INF)cout<<-1<<endl;
        else cout<<ans<<'\n';
    }
    return 0;
}