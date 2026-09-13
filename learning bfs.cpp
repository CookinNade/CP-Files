#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int INF = 1e9+10;
int vis[N]; int lev[N];
vector<pair<int,int>> g[N];
void reset(int n){
    for(int i=1;i<=n;i++) lev[i]=INF;
}
int bfs(int v){
    lev[v]=0;
    deque<int>q;
    q.push_front(v);
    int ans =0;
    while(!q.empty()){
        v=q.front();
        q.pop_front();
        for(auto child : g[v]){
            int cv = child.first; int wt =child.second;
            if(lev[v]+wt < lev[cv]){
                lev[cv]= lev[v]+wt ;
                ans= max(ans,lev[v]+wt);
                if(wt==1) q.push_back(cv);
                else q.push_front(cv);
            }
        }
    }
    return ans;
}

int main () {
    int n,x,y,a,m;
    cin>>n>>m;
    reset(n);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        g[x].push_back({y,0});  g[y].push_back({x,1});
    }
    int realasn=bfs(1);
    for(int i=1;i<=m;i++) cout<<lev[i]<<" ";
    cout<<endl;
    int noer=0;
    for(int i=1;i<=n;i++) if(lev[i]==INF) noer++;
    if(noer)cout<<-1<<endl;
    else cout<<realasn<<endl;
    
    return 0;
    }