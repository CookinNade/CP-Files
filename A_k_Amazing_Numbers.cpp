#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n];
        vector<ll>g[n+1];
        for(int i=0;i<n;i++)g[i].push_back(0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            g[arr[i]].push_back(i+1);
        }
        for(int i=0;i<n;i++)g[i].push_back(n+1);
        ll ans[n+1];
        fill(ans,ans+n+1,n+5);
        for(ll i=1;i<=n;i++){
            d=LLONG_MIN;
            if(g[i].size()<=2)continue;
            for(int j=0;j<g[i].size()-1;j++){
                d=max(d,abs(g[i][j]-g[i][j+1]));
            }
            if(d>=0 and d<=n)
            ans[d]=min(ans[d],i);
        }
        for(int i=1;i<=n;i++){
            ans[i]=min(ans[i],ans[i-1]);
        }
        for(int i=1;i<=n;i++){
            if(ans[i]==n+5)cout<<-1<<" ";
            else cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
    }