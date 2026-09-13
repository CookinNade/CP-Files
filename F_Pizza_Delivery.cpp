#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n; pair<ll,ll> arr[N]; ll b,by;
ll dp[N][2];
ll del(ll i, ll c, ll k){
    if(i>=b)return abs(c-by);
    if(dp[i][k]!=-1)return dp[i][k];
    ll ans=1e16;
    if(c<=arr[i].first){
        ans=min(ans,del(i+1,arr[i].second,1)+arr[i].second-c);
    }
    else if(c>=arr[i].second){
        ans=min(ans,del(i+1,arr[i].first,0)+c-arr[i].first);
    }
    else{
        ans=min(ans,del(i+1,arr[i].first,0)+abs(c-arr[i].second)*2+abs(c-arr[i].first));
        ans=min(ans,del(i+1,arr[i].second,1)+abs(c-arr[i].second)+abs(c-arr[i].first)*2);
    }
    return dp[i][k]=ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,d,cnt,r,l,x; 
    cin>>t;
    string s;
    while (t--){
        ll ax,ay,bx;
        cin>>n>>ax>>ay>>bx>>by;
        map<ll,vector<ll>>mp;
        ll arrx[n];;
        for(int i=0;i<n;i++)cin>>arrx[i];
        for(int i=0;i<n;i++){
            cin>>a;
            mp[arrx[i]].push_back(a);
        }
        b=0;
        for(auto it=mp.begin();it!=mp.end();++it){
            a=(*it).first;
            ll mn=*min_element(mp[a].begin(),mp[a].end());
            ll mx=*max_element(mp[a].begin(),mp[a].end());
            arr[b]={mn,mx};
            b++;
        }
        for(int i=0;i<b;i++){
            dp[i][1]=-1;
            dp[i][0]=-1;
        }
        cout<<del(0,ay,0)+abs(ax-bx)<<endl;
    }
    return 0;
    }