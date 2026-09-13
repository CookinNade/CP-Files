#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long long item;


struct segtree{
    ll size;
    vector<item>sums;
    item Neutral = LLONG_MAX;
    
    

    void init(int n){
        size=1;
        while(size<n)size=size*2;
        sums.assign(size*2, 0ll);
    }

    item merge(item a , item b){
        if(b == Neutral) return a;
        return b;
    }

    void apply_merge(item &a, item b){
        a = merge(a,b);
    }

    void propagate(int x, int lx, int rx){
        if(rx - lx == 1)return;
        apply_merge(sums[2*x + 1], sums[x]);
        apply_merge(sums[2*x + 2], sums[x]);
        sums[x] = Neutral;
    }

    void modify(int l, int r, int v, int x, int lx, int rx){
        propagate(x, lx, rx);
        if(l>=rx or lx>=r) return;
        if(lx>=l and rx<=r){
            apply_merge(sums[x],v);
            return;
        }
        int m=rx+lx;
        m=m/2;
        modify(l,r,v,2*x+1,lx,m);
        modify(l,r,v,2*x+2,m,rx);
    }

    void modify(int l, int r, int v){
        return modify(l,r,v,0,0,size);
    }
    item get(int i, int x, int lx, int rx){
        if(rx-lx==1){
            return sums[x];
        }
        int m=rx+lx;
        m=m/2;
        item res;
        if(i<m) res = get(i,2*x+1,lx,m);
        else res = get(i,2*x+2,m,rx);
        return merge(res,sums[x]);
    }
    item get(int i){
        return get(i,0,0,size);
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
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            ll l,r,v;
            cin>>l>>r>>v;
            st.modify(l,r,v);
        }
        else{
            int i;
            cin>>i;
            cout<<st.get(i)<<'\n';
        }
    }
    return 0;
}