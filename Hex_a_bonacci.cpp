#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll a,b,c,d,e,f,n;
ll dp[10002];
const ll M = 10000007ll;
ll fn(ll n){
    if(dp[n] != -1)return dp[n] % M;
    if (n == 0) return a % M;
    if (n == 1) return b % M;
    if (n == 2) return c % M;
    if (n == 3) return d % M;
    if (n == 4) return e % M;
    if (n == 5) return f % M;
    return dp[n] = (((((fn(n-1) + fn(n-2)) % M + fn(n-3)) % M + fn(n-4)) % M + fn(n-5)) % M  + fn(n-6) )% M;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,cnt,k; 
    int tt = 1;
    cin>>t;
    while (t--){
        cin>>a>>b>>c>>d>>e>>f>>n;
        for(int i=0;i<=n;i++)dp[i] = -1;
        cout<<"Case "<<tt<<": "<<fn(n) % M<<'\n';
        tt++;
    }
    return 0;
    }