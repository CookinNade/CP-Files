#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
struct item{
    // ll seg, pref, suff, sum;
    ll mn , mx;

};
const ll INF  = 1e10;
struct segtree{
    ll size;
    vector<item>sums;
    item Neutral = {INF,0};
    item merge(item a, item b){
        return{
            min(a.mn,b.mn),
            max(a.mx,b.mx)
        };
    }
    item single (ll v){
        return {v,v};
    }
    void init(int n){
        size=1;
        while(size<n)size=size*2;
        sums.resize(size*2);
    }
    void build(vector<ll>&a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < (int)a.size()){
                sums[x]=single(a[lx]);
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        
        sums[x]=merge(sums[2*x+1] , sums[2*x+2]);
    }
    void build(vector<ll>&a){
        build(a,0,0,size);
    }
    
    void set(int i,int v, int x, int lx, int rx){
        if(rx-lx==1){
            sums[x]= single(v);
            return;
        }
        int m=rx+lx;
        m=m/2;
        if(i<m) set(i,v,2*x+1,lx,m);
        else set(i,v,2*x+2,m,rx);
        sums[x]=merge(sums[2*x+1] , sums[2*x+2]);
    }
    void set(int i, int v){
        set(i,v,0,0,size);
    }

    item sum(int l , int r, int x, int lx, int rx){
        if(l>=rx or lx>=r) return Neutral;
        if(lx>=l and rx<=r) return sums[x];
        int m=rx+lx;
        m=m/2;
        item s1,s2;
        s1 = sum(l,r,2*x+1,lx,m);
        s2 = sum(l,r,2*x+2,m,rx);
        return merge(s1,s2);
    }
    item sum (int l, int r){
        return sum(l,r,0,0,size);
    }
};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    segtree st;
    cin>>n>>m;
    st.init(n);
    vector<ll> arr(n);
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]] = i;
    }
    st.build(arr);
    while(m--){
        int l , r;
        cin>>l>>r;
        ll mini  = st.sum(l-1,r).mn;
        ll mixi  =  st.sum(l-1,r).mx;
        ll indmin = mp[mini];
        ll indmax = mp[mixi];
        st.set(indmin,mixi);
        st.set(indmax,mini);
        swap(mp[mini],mp[mixi]);
    }
    ll ans[n];
    for(auto it = mp.begin();it!=mp.end();++it){
        ans[(*it).second] = (*it).first;
    }
    for(auto x:ans)cout<<x<<" ";
    return 0;
}