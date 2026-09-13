#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=1e5+5;
vector<ll>g[N];
ll val[N];
ll h[N];
ll p[N];
vector<pair<int,int>>ve;
pair<ll,ll>d1[N];
pair<ll,ll>d2[N];
ll u[N];
int r;
void he(int v){
    for(auto c:g[v]){
        if(h[c]!=0 or r==c)continue;
        h[c]=h[v]+1;
        p[c]=v;
        he(c);
    }
}
void up(int v){
    if(v==r)return;
    ll y=val[v];
    if(d1[p[v]].first<d1[v].first+y){
        int t=d1[p[v]].first;
        d1[p[v]].first=d1[v].first+y;
        d2[p[v]].first=t;
        t=d1[p[v]].second;
        d1[p[v]].second=v;
        d2[p[v]].second=t;
    }
    else if(d2[p[v]].first<d1[v].first+y){
        d2[p[v]].first=d1[v].first+y;
        d2[p[v]].second=v;
    }
}
void down(int v){

    for(auto c:g[v]){
        if(p[v]==c)continue;
        // if(c==2){
        //     // cout<<"this si par "<<p[c]<<" "<<v<<endl;
        //     // cout<<d1[v].first<<" "<<d1[v].second<<" yo "<<d2[v].first<<" "<<d2[v].second<<endl;
        // }
        if(d1[v].second!=c)u[c]=max(max(0ll,u[v]+val[v]),d1[v].first+val[v]);
        else u[c]=max(max(0ll,u[v]+val[v]),d2[v].first+val[v]);
        down(c);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=0;i<n-1;i++){
        ll a ,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        if((int)g[i].size()==1){
            r=i;
            break;
        }
    }
    he(r);
    for(int i=n;i>=1;i--)ve.push_back({h[i],i});
    sort(ve.rbegin(),ve.rend());
    for(int i=0;i<ve.size();i++)up(ve[i].second);
    down(r);
    while(q--){
        int a;
        cin>>a;
        cout<<max(d2[a].first,u[a])+d1[a].first+val[a]<<'\n';
    }

    return 0;
    }