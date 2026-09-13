#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>g[n+1];
    queue<int>q;
    
    int ans[n+1];
    fill(ans+1,ans+1+n,-1e9);
    ans[1] = 0;
    int cnt[n+1] = {};
    int parent[n+1] = {};
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        cnt[b]++;
    }
    for(int i=1;i<=n;i++)if(cnt[i] == 0)q.push(i);
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto c : g[v]){
            cnt[c]--;
            if(cnt[c]==0)q.push(c);
            if(ans[c] < ans[v] + 1){
                ans[c] = ans[v] + 1;
                parent[c] = v;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<parent[i]<<" "<<ans[i]<<endl;  
    // }
    if(ans[n] <= 0){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<ans[n] + 1<<'\n';
    int v = n;
    vector<int>rasta;
    rasta.push_back(v);
    while(true){
        rasta.push_back(parent[v]);
        v = parent[v];
        if(v==1)break;
    }
    reverse(rasta.begin(),rasta.end());
    for(auto x : rasta)cout<<x<<" ";
    return 0;
    }