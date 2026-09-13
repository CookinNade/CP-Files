#include<bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
typedef ll item;
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
    
    void set(int i, ll v, int x, int lx, int rx){
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
    void set(int i, ll v){
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
    cin>>n>>m;
    segtree st;
    st.init(n);
    vector<ll>arr(n);
    fill(arr.begin(),arr.end(), 0ll);
    // for(auto x:arr)cout<<x<<" ";
    // cout<<endl;
    st.build(arr);
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            ll l,r,v;
            cin>>l>>r>>v;
            // cout<<l<<r<<v<<endl;
            arr[l] += v;
            if(r!=n) arr[r] -= v;
            st.set(l, arr[l]);
            if(r!=n) st.set(r, arr[r]);
        }
        else{
            int i;
            cin>>i;
            // cout<<i<<endl;
            cout<<st.sum(0,i+1)<<endl;
        }
    }
    return 0;
}