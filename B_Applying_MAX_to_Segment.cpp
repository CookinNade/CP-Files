#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long long item;


struct segtree{
    ll size;
    vector<item>sums;
    item Neutral = 0;
    item merge(item a , item b){
        return a + b;
    }
    void init(int n){
        size=1;
        while(size<n)size=size*2;
        sums.resize(size*2);
    }
    void lazyadd(int l, int r, int v, int x, int lx, int rx){
        if(l>=rx or lx>=r) return;
        if(lx>=l and rx<=r){
            sums[x] += v;
            return;
        }
        int m=rx+lx;
        m=m/2;
        lazyadd(l,r,v,2*x+1,lx,m);
        lazyadd(l,r,v,2*x+2,m,rx);
    }

    void lazyadd(int l, int r, int v){
        return lazyadd(l,r,v,0,0,size);
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
            st.lazyadd(l,r,v);
        }
        else{
            int i;
            cin>>i;
            cout<<st.get(i)<<'\n';
        }
    }
    return 0;
}