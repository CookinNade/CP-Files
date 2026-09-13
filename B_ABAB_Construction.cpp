#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll dp[N][3];
string s,p; ll n;
ll laga(ll i, ll k, ll l, ll r){
    if(i>=n){
        return 1;
    }
    if(p[l]==p[r]){
        if(p[l]=='a')k=0;
        else k=2;
    }
    else if(p[l]!=p[r])k=1;
    if(dp[i][k]!=-1)return dp[i][k];
    ll ans=0;
    if(s[i]!=p[l] and s[i]!=p[r] and s[i]!='?') return -100000;
    if(k==0 or k==2){
        ans=laga(i+1,k,l+1,r);
    }
    else if(k==1){
        if(s[i]==p[l])ans=max(ans,laga(i+1,k,l+1,r));
        else if(s[i]==p[r])ans=max(ans,laga(i+1,k,l,r-1));
        else if(s[i]=='?'){
            ans=max(ans,laga(i+1,k,l,r-1));
            ans=max(ans,laga(i+1,k,l+1,r));
        }
    }
    return dp[i][k]=ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,m,a,b,cnt,r,l,k,x; 
    cin>>t;
    for(int i=1;i<=N;i++){
        if(i%2)p.push_back('a');
        else p.push_back('b');
    }
    while (t--){
       cin>>n>>s;
    //    cout<<n<<endl;
       if(n!=s.length()){
            cout<<"NO\n";
            continue;
       }
       for(int i=0;i<3;i++){
            // cout<<n<<endl;
            for(int j=0;j<n;j++)dp[j][i]=-1;
       }
       k=0;
       if(n%2)k=0;
       else k=1;
       ll ans = laga(0,k,0,n-1);
    //    cout<<ans<<endl;
       if(ans>0)cout<<"YES\n";
       else cout<<"NO\n";
    }
    return 0;
    }