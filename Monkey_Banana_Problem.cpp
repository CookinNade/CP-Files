#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int n;
const int N = 201;
vector<int>g[N+2];
int dp[N][N];
int rasta(int i, int j){
    if(i > 2*n - 1)return 0;
    if(i == 2*n -1) {
        // cout<<"it got here\n";
        return g[i][0];

    }
    if(dp[i][j]!=-1)return dp[i][j];
    int csz = (int)g[i].size();
    int nsz = (int)g[i+1].size();
    int ans = 0;
    if(csz < nsz){
        ans = max(ans, g[i][j] + rasta(i+1,j));
        ans = max(ans, g[i][j] + rasta(i+1,j+1));
    }
    else{
        if(j==0) ans = max(ans, g[i][j] + rasta(i+1,0));
        else if(j==csz-1) ans = max(ans, g[i][j] + rasta(i+1,j-1));
        else{
            ans = max(ans, g[i][j] + rasta(i+1,j));
            ans = max(ans, g[i][j] + rasta(i+1,j-1));
        }
    }
    // cout<<i<<" this "<<ans<<'\n';
    return dp[i][j] = ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt,k; 
    cin>>t;
    int tt = 1;
    while (t--){
        cin>>n;
        for(int i=1;i<=2*n-1;i++)g[i].clear();
        for(int i=1;i<=2*n-1;i++){
            for(int j=0;j<i;j++)dp[i][j] = -1;
        }
        k=1;
        for(int i=1;i<=n;i++,k++){
            for(int j=0;j<i;j++){
                int a;
                cin>>a;
                g[i].push_back(a);
            }
        }
        k = n-1;
        for(int i=n+1;k>=1;k--,i++){
            // cout<<"this is k "<<k<<'\n';
            for(int j=0;j<k;j++){
                int a;
                cin>>a;
                g[i].push_back(a);
            }
        }
        // for(auto x:g){
        //     for(auto y:x)cout<<y<<" ";
        //     cout<<'\n';
        // }
        // for(int i=1;i<=2*n-1;i++)cout<<(int)g[i].size()<<'\n';
        cout<<"Case "<<tt<<": "<<rasta(1,0)<<'\n';
        tt++;
    }
    return 0;
    }