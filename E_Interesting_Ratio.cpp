#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e7+1;
ll cnt[N];
ll ans[N];
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,r,l,k,x; 
    for(int i=2;i<=N;i++){
        if(cnt[i])continue;
        cnt[i]++;
        for(int j=i*2;j<=N;j=j+i)cnt[j]++;
    }
    for(int i=1;i<N;i++){
        ans[i]=ans[i-1]+cnt[i];
    }
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
    }