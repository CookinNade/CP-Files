#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1e5+2;
int parent[N];
multiset<int>st;
int sz[N];
int fi(int a){
    if(a == parent[a])return a;
    return parent[a] = fi(parent[a]);
}
void un(int a, int b){
    a = fi(a);
    b = fi(b);
    if(a == b)return;
    if(sz[a] < sz[b]) swap(a,b);
    auto it = st.find(sz[a]);
    st.erase(it);
    it = st.find(sz[b]);
    st.erase(it);
    sz[a] += sz[b];
    parent[b] = a;
    st.insert(sz[a]);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)st.insert(1);
    for(int i=1;i<=n;i++)parent[i] = i;
    for(int i=1;i<=n;i++)sz[i] = 1;
    while(q--){
        int a,b;
        cin>>a>>b;
        // cout<<"ashce\n";
        if(a!=b) un(a,b);
        if(st.size() == 1){
            cout<<0<<'\n';
            continue;
        }
        auto bit = --st.end();
        auto cit = st.begin();
        cout<<(*bit) - (*cit)<<'\n';
    }
    // cout<<parent[3]<<" parent of 3 \n";
    // cout<<parent[4]<<'\n';
    // cout<<fi(4)<<'\n';
    // cout<<fi(1)<<'\n';
    // cout<<parent[1]<<'\n';
    // cout<<fi(3)<<'\n';
    return 0;
    }