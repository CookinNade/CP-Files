#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N =102;
vector<pair<int,int>>g[N];
int vis[N];
int dfs(int chi, int par, int n, int &ans){
    int cnt=0;
    for(auto child:g[chi]){
        
        if(cnt==n-1){
            if(child.first==1){
                ans=ans+child.second;
                break;
            }
            else continue;
        }
        if(child.first==par or vis[child.first])continue;
        // cout<<child.first<<" "<<chi<<" "<<child.second<<endl;
        cnt++;
        ans=ans+child.second;
        vis[child.first]=1;
        dfs(child.first,chi,n,ans);
    }
    return ans;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>x;
        g[a].push_back({b,0}); g[b].push_back({a,x});
    }
    int ans=0;
    int realans = dfs(1,g[1][1].first,n,ans);
    
    // cout<<realans<<endl;

    for(int i=1;i<n+1;i++)vis[i]=0;
    ans=0;
    int ans2=dfs(1,g[1][0].first,n,ans);
    // cout<<ans2<<endl;
    cout<<min(realans,ans2)<<endl;
   
    return 0;
    }