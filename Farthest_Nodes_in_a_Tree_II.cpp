#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 30001;
ll dist[N];
vector<pair<ll,ll>>g[N];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,k; 
    cin>>t;
    while (t--){
        cin>>n;
        ll cnt[n+1];
        fill(cnt,cnt+1+n,0);
        for(int i=0;i<n-1;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            cnt[a]++; cnt[b]++;
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        queue<int>q;
        for(int i=1;i<=n;i++)if(cnt[i]==1)q.push(i);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto c:g[v]){
                cnt[c.first]--;
                if(cnt[c.first] == 1)q.push(c);
            }
        }
    }
    return 0;
    }