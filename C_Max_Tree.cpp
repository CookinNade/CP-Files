#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 2e5+1;

vector<pair<int,pair<int,int>>>g[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        int lcnt = 1;
        int hcnt = n;
        for(int i=0;i<n-1;i++){
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            g[u].push_back({v,{x,y}});
            g[v].push_back({u,{x,y}});
        }
        int incnt[n+1];
        for(int i=1;i<=n;i++)incnt[i] = (int)g[i].size();
        queue<int>q;
        for(int i=1;i<=n;i++)if((int)g[i].size()==1)q.push(i);
        int ans[n+1];
        fill(ans+1,ans+1+n,-1);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto c:g[v]){
                if(ans[c.first] !=-1 )continue;
                int u = c.first;
                int x = c.second.first;
                int y = c.second.second;
                incnt[u]--;
                if(incnt[u] == 1)q.push(u);
                if(v > u){
                    if(x > y){
                        ans [v] = lcnt;
                        lcnt++;
                    }
                    else{
                        ans[v] = hcnt;
                        hcnt--;
                    }
                }
                else{
                    if(x > y){
                        ans[v] = hcnt;
                        hcnt--;
                    }
                    else{
                        ans[v] = lcnt;
                        lcnt++;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(ans[i] == -1){
                ans[i] = lcnt;
                lcnt++;
            }
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<'\n';
        for(int i=1;i<=n;i++)g[i].clear();
    }
    return 0;
    }