#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll rec(vector<ll>&v,ll r){
        ll ans=abs(v[v.size()-1]-v[0]);
        vector<ll> vb;
        for(int i=0;i<v.size()-1;i++){
            vb.push_back(v[i+1]-v[i]);
        }
        if(vb.size()>=2)
        ans= max(ans,abs(rec(vb,0)));
    return ans;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        vector<ll>va(n);
        for(int i=0;i<n;i++)cin>>va[i];
        
        ll ans= accumulate(va.begin(),va.end(),0ll);
        ans=max(ans,abs(va[va.size()-1]-va[0]));
        ans=max(rec(va,0),ans);
        if(n==1){
            cout<<va[0]<<endl;
        }
        else cout<<ans<<endl;
        
    }
    return 0;
    }