#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 5e4 + 2;
const int M = 1e5 + 2; 
int parent[N];
int sz[N];
int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b)return;
    if(sz[a] < sz[b])swap(a,b);
    sz[a] += sz[b];
    parent[b] = a;
    return;
}   
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
    pair<int,pair<int,int>>que[q];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
    }
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        if(s[0] == 'a'){
            que[i].first = 0;
            cin>>que[i].second.first>>que[i].second.second;
        }
        else{
            que[i].first = 1;
            cin>>que[i].second.first>>que[i].second.second;
        }
    }
    reverse(que,que+q);
    vector<bool>ans;
    for(int i=0;i<q;i++){
        if(que[i].first){
            Union(que[i].second.first, que[i].second.second);
        }
        else{
            if(find(que[i].second.first) == find(que[i].second.second)) ans.push_back(true);
            else ans.push_back(false);
        }
    }
    // cout<<ans.size()<<'\n';
    reverse(ans.begin(),ans.end());
    for(auto x:ans){
        if(x)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }