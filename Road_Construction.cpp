#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1e5+2;
int parent[N];
int sz[N];
int find(int a){
    if(a == parent[a])return a;
    return parent[a] = find(parent[a]);
}
pair<int,int> Union(int a, int b){
    if(sz[a] < sz[b])swap(a,b);
    sz[a] += sz[b];
    parent[b] = a;
    return {a,sz[a]};
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
    int hv = 1;
    int hvsz = 1;
    int tot = n;
    while(q--){
        int a,b;
        cin>>a>>b;
        a = find(a);
        b = find(b);
        if(a==b){
            cout<<tot<<" "<<hvsz<<'\n';
            continue;
        }
        tot--;
        pair<int,int>v = Union(a,b);
        if(v.second > hvsz){
            hv = v.first;
            hvsz = v.second;
        }
        cout<<tot<<" "<<hvsz<<'\n';

    }
    return 0;
    }