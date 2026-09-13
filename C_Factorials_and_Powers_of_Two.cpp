#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,t,m,a,b,c,d,cnt,r,l,k; 
    string s;
    a=6;
    vector<ll>v;
    for(ll i=4;;i++){
        if(a>1e12)break;
        if(__builtin_popcount(a)==1)continue;
        v.push_back(a);
        a=a*i;
        if(a>1e12)break;
    }
    cin>>t;
    while (t--){
        cin>>n;
        ll ans = __builtin_popcountll(n);
        r = (1<<15)-1;
        for(ll i=1;i<=r;i++){
            l = __builtin_popcountll(i);
            ll num = 0;
            for(int j=0;j<12;j++){
                if(i&(1<<j))num=num+v[j];
            }
            if(num>n)continue;
            else ans=min(ans,l+__builtin_popcountll(n-num));
        }
        cout<<ans<<endl;
    }
    return 0;
    }