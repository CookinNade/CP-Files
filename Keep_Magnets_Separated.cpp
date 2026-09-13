// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5;
vector<ll>g[N+1];
ll vis[N+1];
// -1
// 3 4 2 1
void dfs(int v){
    vis[v]++;
    cout<<v<<" ";
    for(auto c:g[v]){
        if(vis[c])continue;
        // cout<<c<<" ";
        dfs(c);
    }
}
int k=0;
void len(int v){
    vis[v]++;
    for(auto c:g[v]){
        if(vis[c])continue;
        k++;
        len(c);    
    }
}
int main() {
	int t;
    cin>>t;
    while(t--){
        int n,a,b; 
        cin>>n;
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int no=0;
        for(int i=1;i<=n;i++){
            if((int)g[i].size()==n-1){
                no++;break;
            }
        }
        if(no)cout<<-1<<endl;
        else{
            for(int i=1;i<=n;i++){
                if((int)g[i].size()==1){
                    a=i;break;
                }
            }
            int p=g[a][0];
            vector<pair<int,int>>v;
            vis[p]++;
            for(auto c:g[p]){
                k=1;
                len(c);
                v.push_back({k,c});
            }
            sort(v.begin(),v.end());
            for(int i=1;i<=n;i++)vis[i]=0;
            vis[p]++;
            cout<<p<<" ";
            for(auto c:v){
                dfs(c.second);
            }
            cout<<endl;
        }
        for(int i=1;i<=n;i++)g[i].clear();        
        for(int i=1;i<=n;i++)vis[i]=0;
    }
}
