#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll dp[20][4][2];
string s;
ll lagao(ll i, ll nz, bool smol){
    ll sz = (ll)s.size();
    if(nz > 3)return 0;
    if(i == sz)return 1;
    if(dp[i][nz][smol] != -1) return dp[i][nz][smol];

    ll way = 0;
    // 0 nibo
    bool yes = false;
    if(s[i] != '0') yes = true;
    way = lagao(i+1, nz, yes | smol);
    if(smol){
        way = way + 9ll * lagao(i+1, nz+1, 1);
    }
    else{
        ll mul = s[i] - '0' - 1;
        if(mul > 0) way = way + mul * lagao(i+1,nz+1,1);
        if(s[i] != '0') way =  way + lagao(i+1,nz+1,0);
    }
    return dp[i][nz][smol] = way;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        memset(dp,-1,sizeof(dp));
        ll r,l;
        cin>>l>>r;
        s = to_string(l-1);
        ll lans = lagao(0,0,0);
        s = to_string(r);
        memset(dp,-1,sizeof(dp));
        ll rans = lagao(0,0,0);
        cout<<rans-lans<<'\n';
    }
    return 0;
    }