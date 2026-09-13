#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1e5;
ll dp[3][N+5];
ll a[N],b[N];
ll dz(ll last, ll n){
    
    ll ans = dz(0,n-1)-a[n];
    
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    
    while (t--){
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        

    }
    return 0;
    }