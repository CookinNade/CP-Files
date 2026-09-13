#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef int item;
// struct item{
//     ll seg, pref, suff, sum;
// };

struct segtree{
    int size;
    vector<item>sums;
    item Neutral = 0;
    item merge(item a, item b){
        return a+b;
    }
    item single (int v){
        return v;
    }
    void init(int n){
        size=1;
        while(size<n)size=size*2;
        sums.resize(size*2);
    }
    void build(vector<int>&a, int x, int lx, int rx){
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
    void build(vector<int>&a){
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

    void add(int i, int v, int x, int lx, int rx){
    if(rx-lx==1){
        sums[x] += v; 
        return;
    }
    int m = (lx+rx)/2;
    if(i < m) add(i, v, 2*x+1, lx, m);
    else add(i, v, 2*x+2, m, rx);
    sums[x] = merge(sums[2*x+1], sums[2*x+2]);
    }
    void add(int i, int v){
        add(i, v, 0, 0, size);
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
    int n,m;
    segtree st;
    cin>>n>>m;
    vector<int> arr(n);
    vector<int> orig(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        orig[i] = arr[i];
    }
    
    //preparing queries 
    
    vector<pair<char,pair<int,int>>>q;
    for(int i=0;i<m;i++){
        int a,b;
        char c;
        cin>>c>>a>>b;
        q.push_back({c,{a,b}});
        arr.push_back(a);
        arr.push_back(b);
    }
    
    // co-ordinate compression
    
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()), arr.end());
    
    // building the vector to send to segtree
    int sz = (int)arr.size();
    vector<int>p (sz,0);
    for(int i=0;i<n;i++){
        int x = orig[i];
        auto it = lower_bound(arr.begin(),arr.end(),x);
        int idx = it - arr.begin();
        p[idx]++;
    }
    
    st.init(sz);
    st.build(p);

    for(int i=0;i<m;i++){
        int c = q[i].first;
        int a = q[i].second.first;
        int b = q[i].second.second;
        
        // if(c=='?')cout<<"yo"<<endl;
        if(c == '?'){
            auto it = lower_bound(arr.begin(),arr.end(),a);
            int idx = it - arr.begin();
            a = idx;
            it = lower_bound(arr.begin(),arr.end(),b);
            idx = it - arr.begin();
            b = idx;
            cout<<st.sum(a,b+1)<<'\n';
        }
        else{
            a--;
            int d = orig[a];
            auto it = lower_bound(arr.begin(),arr.end(),d);
            int idx = it - arr.begin();
            d = idx;
            st.add(d,-1);

            orig[a] = b;
            it = lower_bound(arr.begin(),arr.end(),b);
            idx = it - arr.begin();
            b = idx;
            st.add(b,1);
        }

    }

    
    return 0;
}