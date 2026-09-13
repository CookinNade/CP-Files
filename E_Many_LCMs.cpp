#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 998244353;
long long binexp(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
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
        l=1;
        vector<pair<ll,ll>>g[n];
        map<ll,pair<ll,ll>>mpa;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            a=arr[i];
            for(ll j=2;j*j<=a;j++){
                cnt=0;
                if(a%j==0){
                    while(a%j==0){
                        cnt++;
                        a=a/j;
                    }
                    g[i].push_back({j,cnt});
                    if(mpa.find(j)!=mpa.end()){
                        if(mpa[j].first<cnt){
                            mpa[j].second=mpa[j].first;
                            mpa[j].first=cnt;
                        }
                        else if(mpa[j].second < cnt){
                            mpa[j].second=cnt;
                        }
                    }
                    else{
                        mpa[j].first=cnt;
                        mpa[j].second=0;
                    }
                }
            }
            if(a==1)continue;
            g[i].push_back({a,1});
            if(mpa.find(a)!=mpa.end()){
                if(mpa[a].first<1){
                    mpa[a].second=mpa[a].first;
                    mpa[a].first=1;
                }
                else if(mpa[a].second<1){
                    mpa[a].second=1;
                }
            }
            else{
                mpa[a].first=1;
                mpa[a].second=0;
            }
        }
        for(auto it = mpa.begin();it!=mpa.end();++it){
            a=(*it).first; b=(*it).second.first;
            l=(l*binexp(a,b))%M;
        }
        // cout<<l<<endl;
        r=l;
        for(int i=0;i<n;i++){
            ll num=1;
            for(int j=0;j<g[i].size();j++){
                ll f= g[i][j].first; c=g[i][j].second;
                if(mpa[f].first==c)num=num*(binexp(f,c-mpa[f].second));
            }
            num=binexp(num,M-2)%M;
            cout<<(r*num)%M<<" ";
        }
        cout<<endl;
    }
    return 0;
    }