#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
// struct item{
//     ll seg, pref, suff, sum;
// };
typedef int item;

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
        size = 1;
        while(size<n)size = size * 2;
        sums.resize(size * 2);
    }
    void build(vector<ll>&a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)a.size()){
                sums[x]=single(a[lx]);
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        
        sums[x]=merge(sums[2 * x + 1] , sums[2 * x+2]);
    }
    void build(vector<ll>&a){
        build(a, 0, 0, size);
    }
    
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            sums[x]= single(v);
            return;
        }
        int m = (rx + lx) / 2;
        if(i<m) set(i, v, 2*x+1, lx, m);
        else set(i, v, 2*x+2, m, rx);
        sums[x] = merge(sums[2*x+1] , sums[2*x+2]);
    }
    void set(int i, int v){
        set(i,v,0,0,size);
    }
    
    item sum(int l , int r, int x, int lx, int rx){
        if(l >= rx or lx >= r) return Neutral;
        if(lx >= l and rx <= r) return sums[x];
        int m = (rx + lx) / 2;
        item s1,s2;
        s1 = sum(l, r, 2*x+1, lx, m);
        s2 = sum(l, r, 2*x+2, m, rx);
        return merge(s1,s2);
    }
    item sum (int l, int r){
        return sum(l,r,0,0,size);
    }
    // finds the (k+1)th one (1 based indexing)
    int find(int k, int l, int x, int lx, int rx){
        if(l >= rx) return -1;
        if(sums[x] < k)return -1;
        if(rx - lx == 1) return lx;
        int m = (rx + lx) / 2;
        int res = find(k, l, 2*x + 1, lx , m);
        if(res == -1) res =  find(k, l, 2*x + 2, m , rx);
        return res;
    }
    int find(int k, int  l){
        return find(k, l,  0, 0, size);
    }
    //
};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;
    segtree st;
    cin>>n;
    st.init(n);
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll>vis(n);
    for(int i=0;i<n;i++)vis[i] = 0;
    st.build(vis);
    for(int i=0;i<n;i++){
        st.set(arr[i]-1,1);
        // cout<<arr[i]<<endl;
        cout<<st.sum(arr[i],n)<<" ";
    }
    return 0;
}