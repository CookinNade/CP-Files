#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll dp[16][65540];
ll dam[16][16];
int n;
ll biye(int i, int done){
    if(i>=n)return 0;
    if(dp[i][done]!=-1)return dp[i][done];
    
    ll ans = 0;
    for(int j=0;j<n;j++){
        if(!(done & (1ll<<j)))ans = max(ans, biye(i+1,done + (1ll<<j)) + dam[i][j]);
        // cout<<ans<<" "<<i<<" "<<j<<endl;
    }
    return dp[i][done] = ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt,k; 
    cin>>t;
    int tt = 1;
    while (t--){
        cout<<"Case "<<tt++<<": ";
        ll a = 1;
        cin>>n;
        for(int i=0;i<n;i++){
            a*=2;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=a;j++)dp[i][j] = -1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cin>>dam[i][j];
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++)cout<<dam[i][j]<<" ";
        //     cout<<endl;
        // }
        cout<<biye(0,0)<<'\n';
    }
    return 0;
    }