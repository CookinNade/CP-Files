#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll a,b;
string s;
ll dp[20][2];
int sz;
ll dpr(int i, bool smol){
    if(i == sz) return 1ll;
    if(dp[i][smol] != -1) return dp[i][smol];
    ll ways = 0;
    if(smol){
        ways = ways + 9ll * dpr(i+1, 1);
    }
    else{
        // different case handle kora lagbe for i = 0 remember it later
        ll mul;
        if(i == 0 or s[i-1] > s[i]){
            mul = s[i] - '0';
            ways = ways + mul * dpr(i+1, 1);
            ways = ways + dpr(i+1, 0);
        }
        else if(s[i] == '0' and s[i-1] == '0') return 0;
        else{
            // 0,1 er edge case ase
            mul = max(s[i] - '0' - 1, 0);
            ways = ways + mul * dpr(i+1, 1);
            if(s[i] != s[i-1]) ways = ways + dpr(i+1,0);
            
        }
    }
    return dp[i][smol] = ways;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b;


    s = to_string(a-1);
    sz = s.size();
    memset(dp,-1,sizeof(dp));
    ll lans = dpr(0,0);

    s = to_string(b);
    sz = s.size();
    memset(dp,-1,sizeof(dp));
    ll rans = dpr(0,0);
    cout<<lans<<'\n';
    cout<<rans<<'\n';
    cout<<rans-lans<<'\n';
    
    return 0;
    }