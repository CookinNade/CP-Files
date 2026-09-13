#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=2e5;

ll dp[N+5][2];
string s;
vector<ll>v;
ll yo(ll n, ll k){
    if(n==v.size()-1)return 1;
    if(dp[n][k]!=-1)return dp[n][k];
    ll ways=0;
    if(n==0){
        if(v[n]==1)ways=yo(n+1,1);
        if(v[n+1]-v[n]<=2 and n!=v.size()-2)
        ways=max(yo(n+1,0),ways);
        if(n==v.size()-2){
            if(v[n]==s.size()){
                ways=1;
                return dp[n][k]=ways;
            }
        }
    }
    else if(k==1){
        if(s[v[n]-2]=='0')
        ways=yo(n+1,1);
        if(v[n+1]-v[n]<=2 and n!=v.size()-2)
        ways=max(yo(n+1,0),ways);
        if(n==v.size()-2){
            if(v[n]==s.size()){
                ways=1;
                return dp[n][k]=ways;
            }
        }
        // note fo rlater last e n+1 rakha lagbe
    }
    else{
        if(v[n]-v[n-1]==2){
            ways=yo(n+1,1);
        }
        else if(s[v[n]-2]=='0'){
            ways=yo(n+1,1);
            if(v[n+1]-v[n]<=2 and n!=v.size()-2)
            ways=max(ways,yo(n+1,0));
        }
    }
    // cout<<n<<" "<<k<<" "<<ways<<endl;
    return dp[n][k]=ways;
}

 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,c,d,cnt,r,l,k,x; 
    cin>>t;
    while (t--){
        // memset(dp,-1,sizeof(dp));
        cin>>n>>s;
        n=s.size();
        for(int i=0;i<2;i++){
            for(int j=0;j<n+3;j++)dp[j][i]=-1;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0')v.push_back(i+1);
        }
        v.push_back(n+1);
        // for(auto y:v)cout<<y<<" ";

        if(yo(0,1))cout<<"YES\n";
        else cout<<"NO\n";
        v.clear();
    }
    return 0;
    }