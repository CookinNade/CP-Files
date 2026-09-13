#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1e3+5;
const ll M=12001;
ll dp[N][M];
ll res[N];
ll c[N];ll b[N];
ll yo(ll i, ll val, ll n){
    if(i>=n)return 0;
    if(dp[i][val]!=-1)return dp[i][val];
    ll ans=0;
    ans = max(yo(i+1,val,n),ans);
    if(val-res[b[i]]>=0){
        ans=max(ans,yo(i+1,val-res[b[i]],n)+c[i]);
    }
    return dp[i][val]=ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    fill(res,res+1001,14440);
    res[1]=0;
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=i;j++){
            m=i+i/j;
            if(m>1000)continue;
            res[m]=min(res[m],res[i]+1);
            if((i/j)==1)break;
        }
    }
    while (t--){
        cin>>n>>k;
        ll tot=0;
        for(int i=0;i<n;i++){
            cin>>b[i];
            tot=tot+res[b[i]];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=tot;j++){
                dp[i][j]=-1;
            }    
        }
        for(int i=0;i<n;i++)cin>>c[i];
        k=min(k,tot);
        cout<<yo(0,k,n)<<endl;
    }
    return 0;
    }