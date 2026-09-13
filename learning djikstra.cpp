#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;





void djik(int source , vector<int> &dist){
    
    const int N= 1e5+10;
    int vis[N]={0};
    set<pair<int,int>> st;
    
    dist[source]=0;
    st.insert({0,source});
    while(st.size()){
        auto lol = *st.begin();
        int wt= lol.first;
        int chi = lol.second;
        st.erase(lol);
        if(vis[chi])continue;
        vis[chi]=1;
        
        for(auto chil : g[chi]){
            int child = chil.first;
            int childw = chil.second;
            cout<<chi<<" "<<child<<endl;
            if(dist[child]>dist[chi]+childw){
                dist[child]=dist[chi]+childw;
                st.insert({dist[child],child});
            }
        }
        
    }
}
 
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    const int N= 1e5+10;
    const int INF = 1e9+10;
    vector<pair<int,int>> g[N];
    vector<int> dist(N,INF);
    for(auto x: times){
        int a = x[0]; int b = x[1]; int wt = x[2];
        g[a].push_back({b,wt}); 
    }
    
    int vis[N]={0};
    set<pair<int,int>> st;
    
    dist[k]=0;
    st.insert({0,k});
    while(st.size()){
        auto lol = *st.begin();
        int wt= lol.first;
        int chi = lol.second;
        st.erase(lol);
        if(vis[chi])continue;
        vis[chi]=1;
        
        for(auto chil : g[chi]){
            int child = chil.first;
            int childw = chil.second;
            cout<<chi<<" "<<child<<endl;
            if(dist[child]>dist[chi]+childw){
                dist[child]=dist[chi]+childw;
                st.insert({dist[child],child});
            }
        }
        
    }
    int ans=-1;
    for(int i=1;i<=n;i++) ans=max(ans,dist[i]);
    if(ans==INF)return -1;
    return ans;
}   
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,c,d,cnt,r,l,k,x,a,b ;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>x;
        g[a].push_back({b,x});
    }
    djik(1);
    for(int i=1;i<=n;i++){
        // cout<<dist[i]<<" ";
    }cout<<endl;
    
    return 0;
    }