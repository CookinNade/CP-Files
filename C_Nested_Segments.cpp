#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef int item;
// struct item{
//     ll seg, pref, suff, sum;
// };

struct segtree{
    ll size;
    vector<item>sums;
    item Neutral = 0;
    item merge(item a, item b){
        return a+b;
    }
    item single (ll v){
        return v;
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
    ll n,m; cin>>n; segtree st;

    st.init(2*n);

    vector<ll> arr(2*n);
    vector<ll> val(2*n);
    pair<int,int>p[n + 1];

    for(int i=0;i<2*n;i++)val[i] = 0;
    st.build(val);

    for(int i=1;i<=n;i++){
        p[i].second = -1;
        p[i].first = -1;
    }

    for(int i=0;i<2*n;i++){
        cin>>arr[i];
        if(p[arr[i]].first == -1)p[arr[i]].first = i;
        else p[arr[i]].second = i;
    }

    ll ans[n+1];
    fill(ans+1,ans+1+n, 0);
    for(int i=0;i<2*n;i++){
        ll a = arr[i];
        ll li = p[a].first;
        ll ri = p[a].second;
        if(i == ri) {
            ans[a] = st.sum(li,ri);
            st.set(li , 1);
            // cout<<a<<" \n";
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";

    return 0;
}