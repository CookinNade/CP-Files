#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll INF = 1e17;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll g[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cin>>g[i][j];
    }
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    reverse(v.begin(),v.end());
    vector<ll>ans;
    for(int k = 0; k<n; k++){
        ll sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int a = v[i];
                int b = v[j];
                int kv = v[k];
                g[a][b] = min(g[a][b] , g[a][kv] + g[kv][b]);
                if(i<=k and j<=k)sum += g[a][b]; 
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    // cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<" ";
    return 0;
    }