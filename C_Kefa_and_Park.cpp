#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
const int N=1e5+10;
vector<int>g[N];
int wt[N];
int vis[N];
int v[N];
void dfs(int chi , int par, int m){
    for(int child : g[chi]){
        
        if(child==par)continue;
        vis[child]=1;
        if(v[child]==0)wt[child]=0;
        else wt[child]=wt[chi]+v[child];
        if(wt[child]>m)continue;
        dfs(child,chi,m);
    }
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            if(i==1)wt[i]=v[i];
           
        }
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            g[a].push_back(b); g[b].push_back(a);
        }
        dfs(1,0,m);
        // cout<<n<<endl;
        cnt=0;
        // for(int i=1;i<=n;i++)cout<<wt[i]<<" ";
        cout<<endl;
        for(int i=2;i<=n;i++){
            // cout<<wt[i]<<" ";
            if(m>=wt[i] and vis[i] and g[i].size()==1)cnt++;
        }
        // cout<<endl;
        cout<<cnt<<endl;
    return 0;
    }