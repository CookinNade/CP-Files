#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=2e5+3;
ll mn[N];
ll mx[N];
vector<ll>g[N];
ll dp[N][2];
ll dfs(int v, int b, int p){
    if(dp[v][b]!=-1) return dp[v][b];
    ll test1=0;
    for(auto c:g[v]){
        if(p==c){
            if(b==1){
                test1=test1 + abs(mn[v]-mx[c]);
                continue;
            }
            if(b==0){
                test1=test1 + abs(mn[v]-mn[c]);
                continue;
            }
        }
        ll test=dfs(c,0,v);
        test1=test+test1;
    }
    ll test2=0;
    for(auto c:g[v]){
        if(p==c){
            if(b==1){
                test2=test2 + abs(mx[v]-mx[c]);
                continue;
            }
            if(b==0){
                test2=test2 + abs(mx[v]-mn[c]);
                continue;
            }
        }
        ll test=dfs(c,1,v);
        test2=test+test2;
    }
    // cout<<test1<<" "<<test2<<" "<<v<<" "<<p<<" "<<b<<endl;
    return dp[v][b]=max(test1,test2);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            dp[i][0]=-1; dp[i][1]=-1; g[i].clear();
        }
        for(int i=1;i<=n;i++)cin>>mn[i]>>mx[i];
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        ll ans;
        for(int i=1;i<=n;i++){
            if(g[i].size()==1){
                ans=dfs(i,0,0);
                break;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
    }