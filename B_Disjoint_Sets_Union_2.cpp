#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 3e5+2;
int sz[N];
pair<int,int>mm[N];
int parent[N];
int find(int a){
    if(a == parent[a])return a;
    return parent[a] = find(parent[a]);
}
void Union(int a, int b){
    if(sz[a] < sz[b])swap(a,b);
    sz[a] += sz[b];
    parent[b] = a;
    mm[a].first = min(mm[a].first, mm[b].first);
    mm[a].second = max(mm[a].second, mm[b].second);
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        mm[i].first = i;
        mm[i].second = i;
        sz[i] = 1;
        parent[i] = i;
    }
    while(q--){
        string s;
        cin>>s;
        if(s[0] == 'g'){
            int a;
            cin>>a;
            a = find(a);
            cout<<mm[a].first<<" "<<mm[a].second<<" "<<sz[a]<<'\n';
        }
        else{
            int a,b;
            cin>>a>>b;
            a = find(a);
            b = find(b);
            if(a == b)continue;
            Union(a,b);
        }

    }
    return 0;
    }