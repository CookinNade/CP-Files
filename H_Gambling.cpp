#include<bits/stdc++.h>
 
using namespace std;
typedef int ll;
struct item{
    int seg, pref, suff, sum;
};

struct segtree{
    int size;
    vector<item>sums;
    item Neutral = {0,0,0,0};
    item merge(item a, item b){
        return{
            max(a.seg, max(b.seg , a.suff + b.pref)),
            max(a.pref, a.sum + b.pref),
            max(b.suff , b.sum + a.suff),
            a.sum + b.sum
        };
    }
    item single (ll v){
        if(v <= 0){
            return {0,0,0,v};
        }
        else return {v,v,v,v};
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
    while(t--){
        int n;
        cin>>n;
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            mp[a].push_back(i);
        }
        int mx = 0;
        // cout<<mp.size()<<'\n';
        int ans  = -1;
        segtree st;
        for(auto it = mp.begin();it!=mp.end();++it){
            int a = (*it).first;
            vector<int>v;
            v.clear();
            vector<int>b;
            b = (*it).second;
            for(int i=0;i<b.size();i++){
                if(i == 0){
                    v.push_back(1);
                    continue;
                }
                else{
                    if(b[i-1] + 1 == b[i])v.push_back(1);
                    else {
                        v.push_back(-b[i] + b[i-1] + 1);
                        v.push_back(1);
                    }
                }
            }
            int sz = (int)v.size();
            st.init(sz);
            st.build(v);
            int res = st.sum(0,sz).seg;
            // cout<<res<<" "<<a<<'\n';
            if(res > mx){
                mx = res;
                ans = a;
            }
            // mx = max(mx, res);
        }
        vector<int>b;
        vector<pair<int,int>>v;
        // ans = 8; // to be commented out later
        b = mp[ans];
        for(int i=0;i<b.size();i++){
            if(i == 0){
                v.push_back({1,b[i]});
                continue;
            }
            else{
                if(b[i-1] + 1 == b[i])v.push_back({1,b[i]});
                else {
                    v.push_back({-b[i] + b[i-1] + 1,0});
                    v.push_back({1,b[i]});
                }
            }
        }
        int s = v[0].second, e = 0;
        int curr = 0;
        int mxx = 0;
        int fs = 0, fe = 0;
        for(int i=0;i<v.size();i++){
            curr +=v[i].first;
            if(curr <= 0){
                if(i != (int)v.size() - 1)
                s = v[i+1].second;
                curr = 0;
            }
            if(curr > mxx){
                fs = s;
                fe = v[i].second;
                mxx = curr;
            }
        }
        cout<<ans<<" "<<fs+1<<" "<<fe+1<<'\n';
    }
    
    return 0;
}