#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 503;
ll arr[N];
ll dp[N][N];
set<ll>st;
ll valuebanabo(ll n , ll sum, set<ll> &st, ll k){
    int yesser=0;
    for(int i=0;i<n;i++){
        if(st.find(i)==st.end() and sum+arr[i]<=k){
            valuebanabo()
        }
    }
    


}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    string s;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>arr[i];

    return 0;
    }