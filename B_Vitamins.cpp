#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
vector<ll>ans;
const ll  N=1e3+2;
ll price[N];
string s[N];
ll dp[9][N];
ll dpz(ll n , ll val){

    if(n<0){
        if (val==7) return 0;
        else return 1e14;
    }
    if(dp[val][n]!=-1)return dp[val][n];
    ll old =val;
    for(int i=0;i<s[n].size();i++){
        if(s[n][i]=='A')val = val | (1<<0);
        else if(s[n][i]=='B')val = val | (1<<1);
        else val = val | (1<<2); 
    }
    ll an =1e14;
    an=dpz(n-1, old);
    an = min(an,dpz(n-1,val)+price[n]);
    // if(val==7) ans.push_back(an);
    return dp[old][n]=an;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>price[i]>>s[i];
    ll real = dpz(n-1,0);
    if(real ==1e14)cout<<-1<<endl;
    else cout<<real<<endl;
    
    // cout<<ans.size()<<endl;
    // for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
    // cout<<endl;
    return 0;
    }