#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,c;
    cin>>n;
    ll arr[n+1];
    ll ans[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    vector<ll>v;
    bool vis[n+1];
    fill(vis,vis+1+n,false);
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        v.push_back(i);
        c=i;
        while(true){
            ll d=arr[c];
            v.push_back(d);

            if(d==c)break;
            else if(vis[d]){
                ans[c]=ans[d];
            }
            c=d;
        }
        for(int k=0;k<v.size();k++){
            ans[v[k]]=c;
            vis[v[k]]=true;
        }
        v.clear();
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";

    return 0;
    }