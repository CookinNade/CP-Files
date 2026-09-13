#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll w[n+1];
        w[0]=0;
        vector<ll>g[n+1];
        for(int i=0;i<n;i++)cin>>w[i+1];
        ll ans=accumulate(w+1,w+1+n,0ll);
        vector<ll>v;
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            g[a].push_back(b); swap(a,b); g[a].push_back(b);
        }
        for(int i=1;i<=n;i++){
            ll r=g[i].size()-1;
            for(int j=0;j<r;j++)v.push_back(i);
        }
        for(int i=0;i<v.size();i++)v[i]=w[v[i]];
        sort(v.rbegin(),v.rend());
        cout<<ans<<" ";
        for(int i=0;i<v.size();i++){
            ans=ans+v[i];
            cout<<ans<<" ";
        }
        cout<<endl;
        // for(auto x:v)cout<<x<<" ";
    }
    return 0;
    }