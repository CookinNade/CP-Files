#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 1e5+2;
int parent[N];
int sz[N];
int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}
void Union(int a, int b){
    if(sz[a] < sz[b])swap(a,b);
    sz[a] += sz[b];
    parent[b] = a;
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        parent[i] = i;
        sz[i] = i;
    }
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        if(s[0] == 'u'){
            int a , b;
            cin>>a>>b;
            a = find(a);
            b = find(b);
            if(a == b)continue;
            Union(a,b);
        }
        else{
            int a,b;
            cin>>a>>b;
            if(find(a) == find(b))cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
    }