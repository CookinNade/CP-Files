#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 1e9+7;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>g[n+1];
    queue<int>q;
    
    ll cnt[n+1] = {};
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        cnt[b]++;
    }
    for(int i=1;i<=n;i++)if(cnt[i]==0)q.push(i);

    ll ans[n+1] = {};
    fill(ans+1,ans+1+n,0);
    ans[1] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto c:g[v]){
            cnt[c]--;
            if(cnt[c] == 0)q.push(c);
            ans[c] = (ans[c] + ans[v]) % M;
        }
    }
    cout<<max(0ll,ans[n]);
    return 0;
    }