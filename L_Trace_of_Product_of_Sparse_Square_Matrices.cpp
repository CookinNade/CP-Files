#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin>>n;
    map<ll,vector<pair<ll,ll>>>mpa;
    map<pair<ll,ll>,ll>mpb;
    cin>>k;
    for(int i=0;i<k;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        mpa[a].push_back({b,c});
    }
    cin>>k;
    for(int i=0;i<k;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        mpb[{a,b}]=c;
    }
    // for(auto it = mpb.begin(); it!=mpb.end(); ++it){
    //     cout<<(*it).first.first<<" "<<(*it).first.second<<" "<<(*it).second<<endl;
    // }
    ll ans = 0;
    ll M = 1006903069ll;
    for(auto it = mpa.begin(); it!=mpa.end(); ++it){
        ll a = (*it).first;
        ll b , x;
        for(int i = 0; i<mpa[a].size(); i++){
            b = mpa[a][i].first;
            x = mpa[a][i].second;
            if(mpb.find({b,a}) != mpb.end()){
                ll sum = (x * mpb[{b,a}]) % M;
                ans = (ans + sum) % M;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
    }