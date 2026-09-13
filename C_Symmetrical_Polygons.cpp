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
    while (t--){
        cin>>n;
        vector<ll>v;
        map<ll,ll>mp;
        for(int i=0;i<n;i++){
            cin>>a;
            mp[a]++;
        }
        ll side=0;
        ll ans=0;
        for(auto it = mp.begin();it!=mp.end();++it){
            ll s=(*it).first;
            m =(*it).second;
            ll num =m/2;
            ans = ans + (num*2ll*s);
            side = (num*2ll) + side;
            if(m%2)v.push_back(s);
            // cout<<s<<" "<<m<<" "<<num*2ll<<" "<<m%2<<endl;
        }
        sort(v.begin(),v.end());
        // cout<<ans<<endl;
        int sz=v.size();
        if(sz==1 and ans>v[0]){
            ans = ans + v[0];
            side++;
        }
        if(sz>=2){
            r=sz-1;
            l=sz-2;
            for(;l>=0;l--,r--){
                if(ans> v[r]-v[l]){
                    ans = ans+v[r]+v[l];
                    side=side+2;
                    break;
                }
                // cout<<l<<" ";
            }
            // cout<<"dhukse "<<l<<endl;
            if(l==-1){
                l=sz-1;
                for(;l>=0;l--){
                    if(ans>v[l]){
                        ans=ans+v[l];
                        side++;
                        break;
                    }
                }
            }
        }
        // cout<<ans<<endl;
        // cout<<side<<endl;
        if(side<=2)cout<<0<<endl;
        else cout<<ans<<endl;
    }
    return 0;
    }