#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>g[n+1];
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    queue<int>q;
    int cnt[n+1];
    for(int i=1;i<=n;i++) cnt[i] = (int)g[i].size();
    for(int i=1;i<=n;i++) if(cnt[i] == 1) q.push(i);
    int ans = 0;
    bool use[n+1];
    fill(use, use+1+n,false);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto c:g[v]){
            cnt[c]--;
            if(cnt[c] == 1)q.push(c);
            if(!use[c] and !use[v]){
                use[c] = true;
                use[v] = true;
                ans++;
            }
        }
    }
    
    cout<<ans<<'\n';
    return 0;
    }