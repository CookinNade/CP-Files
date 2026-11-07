#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll M = 1e9+7;
const int W = 15001;
const int N = 151;

ll dp1[N][W];
ll dp2[N][W];

ll has(int i, int rem, vector<int>&coins){
    if(dp1[i][rem]!=-1)return dp1[i][rem];
    if(rem == 0)return 1;
    if(i == (int)coins.size())return 0;
    ll way = 0;
    if(rem >= coins[i]) way = (way +  has(i+1,rem-coins[i],coins)) % M;
    way = (way + has(i+1,rem,coins)) % M; 
    return dp1[i][rem] = way;
}
ll bob(int i, int rem, vector<int>&coins){
    if(dp2[i][rem]!=-1)return dp2[i][rem];
    if(rem == 0)return 1;
    if(i == (int)coins.size())return 0;
    ll way = 0;
    if(rem >= coins[i]) way = (way +  bob(i+1,rem-coins[i],coins)) % M;
    way = (way + bob(i+1,rem,coins)) % M;
    return dp2[i][rem] = way % M;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,w;
        cin>>n>>m>>k>>w;
        vector<int>coins1(n);
        vector<int>coins2(m);
        for(int i=0;i<n;i++)cin>>coins1[i];
        for(int i=0;i<m;i++)cin>>coins2[i];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=w;j++)dp1[i][j] = -1;
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=w;j++)dp2[i][j] = -1;
        }
        ll ans = 0;
        for(int i=0;i<=w;i++){
            int s1 = i;
            int s2 = w - i;
            if(abs(s1-s2) > k)continue;
            ll way1 = has(0,s1,coins1);
            ll way2 = bob(0,s2,coins2);
            ll barbe = (way1 * way2) % M;
            ans = (ans + barbe) % M;
        }
        cout<<ans<<'\n';
    }
    return 0;
    }