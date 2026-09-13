#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2e5;

ll dp[N+5][2];
ll arr[N+5];
ll n;
ll noob(ll i,ll p){
    if(i>=n)return 0;
    if(dp[i][p]!=-1)return dp[i][p];
    ll ans=1e12;
    if(p){
        ans=min(ans,noob(i+1,0)+arr[i]);
        ans=min(ans,noob(i+2,0)+arr[i]+arr[i+1]);
    }
    else{
        ans=min(ans,noob(i+1,1));
        ans=min(ans,noob(i+2,1));
    }
    return dp[i][p]=ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        for(int i=0;i<2;i++){
            for(int j=0;j<=n+2;j++)dp[j][i]=-1;   
        }
        for(int i=0;i<n;i++)cin>>arr[i];
        cout<<noob(0,1)<<endl;
    }
    return 0;
    }