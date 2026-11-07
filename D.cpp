#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N  = 3e6+2;
int parent[N];
int sz[N];
int find(int a){
    if(a == parent[a])return a;
    return parent[a] = find(parent[a]);
}
void Union(int a, int b){
    if(sz[b]>sz[a])swap(a,b);
    sz[a]+=sz[b];
    parent[b]=a;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    n*=3;
    for(int i=1;i<=n;i++)parent[i] = i, sz[i] = 1;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a = find(a);
        b = find(b);
        if(a!=b)Union(a,b);
    }
    vector<int>v;
    for(int i=1;i<=n;i++){
        if(i == find(i) and sz[i]%3)v.push_back(sz[find(i)]%3);
        // cout<<i<<" "<<find(i)<<" "<<sz[i]<<endl;
    }
    sort(v.rbegin(),v.rend());
    ll ans = 0;
    int r = (int)v.size()-1;
    int ase = 0;
    // for(auto x:v)cout<<x<<" ";
    for(int l=0;;){
        if(l>=r)break;
        if(v[l] + v[r] == 4){
            ans += 8;
            l+=2;
            r--;
        }
        else if(v[l] + v[r] == 3){
            ans += 4;
            l++;
            r--;
        }
        else if(v[l] + v[r] == 2){
            ans += 6;
            l+=2;
            r--;
        }
    }
    cout<<ans;
    return 0;
    }