#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long long item;

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
    ll n,m;
    segtree st;
    cin>>n;
    st.init(n);
    vector<ll> arr(n);
    for(int i=0;i<n;i++)arr[i] = 1;
    int ind[n+1];
    set<int>v;
    for(int i=0;i<n;i++){
        int a;
        v.insert(i);
        cin>>a;
        ind[a] = i;
    }
    st.build(arr);
    int e = n-1;
    vector<int>ans;
    for(int i=n;i>=1;i--){
        if(i == 1){
            ans.push_back(1);
            break;
        }
        int cur = ind[i];
        if(e >= cur){
            ans.push_back(st.sum(cur,e+1));
            // cout<<st.sum(cur,e+1)<<" ";
        }
        else{
            ans.push_back(st.sum(cur,n) + st.sum(0,e+1));
            // cout<<st.sum(cur,n) + st.sum(0,e+1)<<" ";
        }
        auto it = v.lower_bound(cur);
        if(it == v.begin()){
            it = --v.end();
            e = (*it);
        }
        else{
            --it;
            e = (*it);
        }
        st.set(cur,0);
        v.erase(cur);
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)cout<<x<<" ";
    return 0;
}