#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1e5+1;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,x; 
    ll dp[N];
    ll freq[N];
    cin>>n;
    fill(freq,freq+N,0ll);
    for(int i=0;i<n;i++){
        cin>>a;
        freq[a]++;
    }
    dp[1]=freq[1];
    dp[2]=max(freq[1],2*freq[2]);
    
    for(ll i=3;i<N;i++){
        dp[i]=max(dp[i-1],i*freq[i]+dp[i-2]);
    }
    cout<<dp[N-1]<<endl;
    
    return 0;
    }