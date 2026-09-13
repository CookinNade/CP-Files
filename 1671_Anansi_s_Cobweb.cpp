#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 1e5+2;

int parent[N];
int sz[N];
int find(int a){
    if(a == parent[a])return a;
    return parent[a] = find(parent[a]);
}
void Union(int a, int b){
    if(sz[a] < sz[b])swap(b,a);
    parent[b] = a;
    sz[a] += sz[b];
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
    pair<int,int>edge[m+1];
    bool use[m+1];
    fill(use,use+m+1,true);
    for(int i=1;i<=m;i++){
        cin>>edge[i].first>>edge[i].second;
    }
    int q;
    cin>>q;
    int que[q];
    for(int i=0;i<q;i++){
        cin>>que[i];
        use[que[i]] = false;
    }
    reverse(que,que+q);
    for(int i=1;i<=m;i++){
        if(use[i]){
            int a = find(edge[i].first);
            int b = find(edge[i].second);
            if(a!=b) Union(a,b); 
        }
    }
    int ans = 0;
    vector<int>v;
    for(int i=1;i<=n;i++)if(parent[i] == i)ans++;
    for(int i=0;i<q;i++){
        int num = que[i];
        int a = find(edge[num].first);
        int b = find(edge[num].second);
        v.push_back(ans);
        if(a == b)continue;
        Union(a,b);
        ans--;
    }
    reverse(v.begin(),v.end());
    for(auto x:v)cout<<x<<" ";

    return 0;
    }