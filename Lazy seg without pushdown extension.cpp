#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long long item;
// struct item{
//     ll seg, pref, suff, sum;
// };
// MUST HAVE THE property of something like min(a+v , b+v) = min(a,b) + v;
// theory : then moment we find a node which covers the whole segment that we want,
// we apply the operation. which is add here. after that, we update the minimum.
// minimum is updated every node. but to get the actual value of the minimum we also need to
// add the add operation values stored in uporer nodes. 
struct segtree{
    ll size;
    vector<item>sums;
    vector<item>mins;
    item Neutral = 0;
    item INF = LLONG_MAX;
    item merge(item a , item b){
        return a + b;
    }
    item get_min_merge(item a, item b){
        return min(a,b);
    }
    void init(int n){
        size=1;
        while(size<n)size=size*2;
        sums.assign(size*2,0ll);
        mins.assign(size*2,0ll);
    }
    void lazyadd(int l, int r, int v, int x, int lx, int rx){
        if(l>=rx or lx>=r) return;
        if(lx>=l and rx<=r){
            sums[x] += v;
            mins[x] += v;
            return;
        }
        int m=rx+lx;
        m=m/2;
        lazyadd(l,r,v,2*x+1,lx,m);
        lazyadd(l,r,v,2*x+2,m,rx);
        mins[x] = get_min_merge(mins[2*x+1],mins[2*x+2]) + sums[x];
        // applying addition of nijer levels after getting the mins using +sums[x];
    }

    void lazyadd(int l, int r, int v){
        return lazyadd(l,r,v,0,0,size);
    }
    long long get_min(int l, int r, int x, int lx, int rx){
        if(l>=rx or lx>=r) return INF;
        if(lx>=l and rx<=r){
            return mins[x]; 
        }
        int m=rx+lx;
        m=m/2;
        ll m1  = get_min(l,r,2*x+1,lx,m);
        ll m2 = get_min(l,r,2*x+2,m,rx);
        return get_min_merge(m1,m2) + sums[x]; // applying addition of uporer levels after getting the mins using +sums[x]
    }
    long long get_min(int l, int r){
        return get_min(l,r,0,0,size);
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
            int r,l;
            cin>>l>>r;
            cout<<st.get_min(l,r)<<'\n';
        }
    }
    return 0;
}