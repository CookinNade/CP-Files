#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
struct item{
    pair<ll,ll> arr[41] ={};
};

struct segtree{
    ll size;
    vector<item>sums;
    item Neutral = {};
    item merge(item a, item b){
        ll sum = 0;
        item res;
        res.arr[40].first = a.arr[40].first + b.arr[40].first;
        for(int i=39;i>=0;i--){
            sum += a.arr[i+1].first;
            res.arr[i].first = a.arr[i].first + b.arr[i].first;
            res.arr[i].second = (sum * b.arr[i].first) + a.arr[i].second + b.arr[i].second;
            res.arr[i].second = (sum * b.arr[i].first) + a.arr[i].second + b.arr[i].second;
        }
        return res;
    }
    item single (ll v){
        item res;
        if(v>=0 and v<=40){
            res.arr[v].first = 1;
        }
        return res;
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
    
    void set(int i,ll v, int x, int lx, int rx){
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

    // add function: useful when using co-ordinate compression
    // adds v to the ith index
    // apatoto keep it commented so that it doesnt mess with struct item, useful when item is used as
    
    // void add(int i, int v, int x, int lx, int rx){
    // if(rx-lx==1){
    //     sums[x] += v; 
    //     return;
    // }
    // int m = (lx+rx)/2;
    // if(i < m) add(i, v, 2*x+1, lx, m);
    // else add(i, v, 2*x+2, m, rx);
    // sums[x] = merge(sums[2*x+1], sums[2*x+2]);
    // }
    // void add(int i, int v){
    //     add(i, v, 0, 0, size);
    // }

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
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    st.build(arr);

    // cout<<"all good\n";
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int x,y;
            cin>>x>>y;
            item res = st.sum(x-1,y);
            ll sum = 0;
            for(int i = 0;i<41;i++){
                // cout<<i<<" "<<res.arr[i].first<<" "<<res.arr[i].second<<endl;
                if(res.arr[i].first == 0)continue;
                else sum += res.arr[i].second;
            }
            cout<<sum<<'\n';
        }
        else{
            int x,y;
            cin>>x>>y;
            st.set(x-1,y);
        }
    }
    return 0;
}