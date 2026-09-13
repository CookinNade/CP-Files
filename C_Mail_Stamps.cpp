#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
map<ll,vector<ll>>mp;
map<ll,bool>vis;
void dfs(ll v){
    vis[v]=true;
    for(auto child:mp[v]){
        if(vis[child])continue;
        cout<<child<<" ";
        dfs(child);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,a,b;
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
        vis[a]=false;vis[b]=false;
    }
    ll ch;
    for(auto it=mp.begin();it!=mp.end();++it){
        if((*it).second.size()==1){
            ch=(*it).first;
            break;
        }
    }
    cout<<ch<<" ";
    dfs(ch); 
    return 0;
    }