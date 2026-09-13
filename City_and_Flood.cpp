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
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(sz[a] < sz[b])swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(parent[i] == i)ans++;
    }
    cout<<ans;

    return 0;
    }