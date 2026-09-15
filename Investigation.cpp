#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1e4 + 2;
ll dp[10][100][100][2];
ll a,b,k;
string s;
ll n;
ll way(int i, int mod, int sum, int c){
    if(s == "0") return 1ll;
    if(i == n and mod == 0 and sum == 0) return 1ll;
    else if(i == n)return 0;
    if(dp[i][mod][sum][c] != -1)return dp[i][mod][sum][c];
    ll p = n - i - 1;
    ll mul = 1;
    for(int j=0;j<p;j++) mul *= 10;
    ll mx = s[i] - '0';
    ll cnt = 0;
    if(i == 0){
        cnt += way(i+1,mod,sum,1);
        for(ll j = 1;j<mx;j++){
            ll jabe = (mod + mul * j) % k;
            ll sm = (sum + j) % k;
            cnt += way(i+1, jabe, sm, 1);
        }
        ll jabe = (mod + mul * mx) % k;
        ll sm = (sum + mx) % k;
        cnt += way (i+1, jabe, sm, 0);
        return dp[i][mod][sum][c] = cnt;
    }
    if(c){
        for(ll j = 0;j<=9;j++){
            ll jabe = (mod + mul * j) % k;
            ll sm = (sum + j) % k;
            cnt += way(i+1, jabe, sm, 1);
        }
    }
    else{
        for(ll j = 0;j<mx;j++){
            ll jabe = (mod + mul * j) % k;
            ll sm = (sum + j) % k;
            cnt += way(i+1, jabe, sm, 1);
        }
        ll sm = (sum + mx) % k;
        ll jabe = (mod + mul * mx) % k;
        cnt += way (i+1, jabe, sm , 0);
    }
    return dp[i][mod][sum][c] = cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt; 
    int tt = 1;
    cin>>t;
    while (t--){
        cout<<"Case "<<tt++<<": ";
        cin>>a>>b>>k;
        a--;
        if(k == 1){
            cout<<b-a<<'\n';
            continue;
        }
        if(k > 90){
            cout<<0<<'\n';
            continue;
        }
        memset(dp,-1,sizeof(dp));
        s = to_string(b);
        n = (int)s.size();
        ll B = way(0,0,0,0);

        // cout<<B<<" this is B\n";
        // cout<<s<<endl;

        memset(dp,-1,sizeof(dp));
        s = to_string(a);
        n = (int)s.size();
        ll A = way(0,0,0,0);

        cout<<B-A<<'\n';

        // cout<<s<<endl;
        // cout<<A<<" this is A\n";
        // string tes = to_string((1ll<<31));
        // cout<<tes<<" sz "<<tes.size()<<endl;
    }
    return 0;
    }