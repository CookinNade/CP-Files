#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        vector<ll>b;
        cin>>n>>m;
        for(int i=0;i<63;i++){
            if(m&(1ll<<i))b.push_back(i);
        }
        r=n;
        for(int i=b.size()-1;i>=0;i--){
            ll num =1ll<<b[i];
            if(num>r)continue;
            else{
                c=r/num;
                r=r-(c*num);
            }
        }
        if(r!=0){
            cout<<-1<<endl;
            continue;
        }
        vector<pair<ll,ll>>v;
        r=n;
        for(int i=b.size()-1;i>=0;i--){
            ll num =1ll<<b[i];
            if(num>r)v.push_back({b[i],0});
            else{
                v.push_back({b[i],r/num});
                c=r/num;
                r=r-(c*num);
            }
        }
        // for(int i=0;i<b.size();i++){

        // }
        // for(int i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second<<endl;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(v[i].second>v[j].second){
                    d=v[i].first-v[j].first;
                    c=(1ll<<d);
                    l=v[i].second-v[j].second;
                    k = l/c;
                    v[i].second=v[i].second-k;
                    v[j].second=v[j].second+k*c;
                    cout<<v[i].first<<" "<<v[j].first<<" "<<v[i].second<<" "<<v[j].second<<endl; 
                }
            }
        }
        for(int i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second<<endl;
        ll ans=0;
        for(int i=0;i<v.size();i++)ans=max(ans,v[i].second);
        cout<<ans<<endl;
    }
    return 0;
    }