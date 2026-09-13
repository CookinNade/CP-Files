#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
const ll N = 105;
ll dp[N][100005];
ll arr[N];
ll wt[N];

ll knp(ll n,ll left){
    ll ans;
    if(n<0)return 0;
    if(left==0) return 0;
    if(dp[n][left]!=-1)return dp[n][left];
    ans = knp(n-1,left);
    if(left>=wt[n]) ans = max(ans,knp(n-1,left-wt[n])+arr[n]);
    return dp[n][left]=ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k; 
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>wt[i]>>arr[i];
    cout<<knp(n-1,k)<<endl;
    return 0;
    }