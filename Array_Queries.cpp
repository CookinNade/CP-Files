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
    item Neutral = 1e5 + 3;
    item merge(item a, item b){
        return min(a,b);
    }
    item single (item v){
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

    // rough template on binary search
    
    // int find(int k, int x, int lx, int rx){
    //     int m = rx + lx;
    //     m = m/2;
    //     if(rx-lx == 1) return lx;
    //     if (sums[2*x + 1] > k){
    //         return find(k, 2*x + 1, lx , m);
    //     }
    //     else return find (k - sums[2*x + 1], 2*x+2, m, rx);
    // }
    // int find(int k){
    //     return find(k, 0, 0, size);
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
    int t;
    cin>>t;
    int tt = 0;
    while(t--){
        tt++;
        int n,m;
        segtree st;
        cin>>n>>m;
        st.init(n);
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        st.build(arr);
        cout<<"Case "<<tt<<":\n";
        while(m--){
            int i , j;
            cin>>i>>j;
            cout<<st.sum(i-1,j)<<'\n';
        }
    }
    return 0;
}