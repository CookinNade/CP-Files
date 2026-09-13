#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 2e5+2;
int parent[N];
int sz[N];
set<int>g[N+1];
int find(int a){
    if(a == parent[a])return a;
    return parent[a] = find(parent[a]);
}
void Union(int a, int b){
    if(sz[a] < sz[b])swap(a,b);
    if(b==1)swap(a,b);
    for(auto it = g[b].begin();it!=g[b].end();++it){
        g[a].insert((*it));
    }
    parent[b] = a;
    sz[a] += sz[b];
    g[b].clear();
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    pair<int,int>edge[n+1];
    for(int i=1;i<=n;i++){
        cin>>edge[i].first>>edge[i].second;
        sz[i] = 1;
        parent[i] = i;
        g[i].insert(i);
    }
    pair<int,int> cut[q];
    pair<bool,bool>yes[n+1];
    for(int i=1;i<=n;i++){
        yes[i].first = true;
        yes[i].second = true;
    }
    for(int i=0;i<q;i++){
        int v,h;
        cin>>v>>h;
        if(h == 1) yes[v].first = false;
        else yes[v].second = false;
        cut[i].first = v;
        cut[i].second = h;
    }
    int fall[n+1];
    fill(fall,fall+n+1,q+5);
    fall[1] = -1;
    for(int i=1;i<=n;i++){
        if(yes[i].first and edge[i].first != -1){
            int a = i;
            int b = edge[i].first;
            a = find(a);
            b = find(b);
            
            if(b == 1)swap(a,b);
            if(a==1 and a!=b){
                for(auto it=g[b].begin();it!=g[b].end();++it){
                    fall[(*it)] = -1;
                }
            }
            if(a != b)Union(a,b);
        }
        if(yes[i].second and edge[i].second != -1){
            if(yes[i].second and edge[i].second != -1){
                int a = i;
                int b = edge[i].second;
                a = find(a);
                b = find(b);
                if(b == 1)swap(a,b);
                if(a==1 and b!=a){
                    for(auto it=g[b].begin();it!=g[b].end();++it){
                        fall[(*it)] = -1;
                    }
                }
                if(a!=b)Union(a,b);
            }
        }
    }
    reverse(cut,cut+q);
    int m = q-1;
    for(int i=0;i<q;i++){
        int a = cut[i].first;
        int h = cut[i].second;
        int b;
        if(h==1)b = edge[a].first;
        else b = edge[a].second;
        int pa = find(a);
        int pb = find(b);
        if(pb == 1)swap(pb,pa);
        if(pa != pb and pa==1){
            for(auto it = g[pb].begin();it!=g[pb].end();++it)fall[(*it)] = min(fall[(*it)],m);
        }
        m--;
        if(pa == pb)continue;
        Union(pa,pb);
    }
    for(int i=1;i<=n;i++)cout<<fall[i]<<'\n';

    return 0;
    }