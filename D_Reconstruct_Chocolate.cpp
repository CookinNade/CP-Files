#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,w,h,a,b;
    cin>>h>>w>>n;
    map<ll,set<pair<ll,ll>>>he;
    map<ll,set<pair<ll,ll>>>wi;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        he[a].insert({b,i});
        wi[b].insert({a,i});
        // cout<<i<<" "<<a<<" "<<b<<endl;
    }
    ll cw=1,ch=1;
    pair<ll,ll>ans[n];
    // ll vis[n];
    // fill(vis,vis+n,false);
    for(int i=0;i<n;i++){
        // cout<<i<<" "<<h<<" "<<w<<" "<<ch<<" "<<cw<<endl;
        if(wi.find(w)!=wi.end()){
            auto it = wi[w].begin();
            ll m=(*it).first;
            ll ind=(*it).second;
            // cout<<ind<<" yo from w "<<m<<" "<<h<<" "<<i<<endl;
            ans[ind]={ch,cw};
            ch=ch+m;
            h=h-m;
            he[m].erase({w,ind});
            wi[w].erase({m,ind});
            if(wi[w].size()==0)wi.erase(w);
            // cout<<i<<" from w "<<ind<<" "<<m<<endl;
            continue;
        }
        if(he.find(h)!=he.end()){
            auto it = he[h].begin();
            ll m=(*it).first;
            ll ind=(*it).second;
            // cout<<ind<<" yo from h "<<m<<" "<<h<<endl;
            ans[ind]={ch,cw};
            cw=cw+m;
            w=w-m;
            // cout<<w<<endl;
            wi[m].erase({h,ind});
            he[h].erase({m,ind});
            if(he[h].size()==0)he.erase(h);
            // cout<<i<<" from h "<<ind<<" "<<m<<endl;
        }
    }
    for(int i=0;i<n;i++)cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    return 0;
    }