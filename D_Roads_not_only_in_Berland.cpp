#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 1001;
int parent[N];
int sz[N];
int find(int a){
    if(a == parent[a])return a;
    return parent[a] = find(parent[a]);
}
void Union(int a, int b){
    if(sz[a] < sz[b])swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
    vector<pair<int,int>> loop;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;

        int c = find(a);
        int d = find(b);
        if(c!=d)Union(c,d);
        else loop.push_back({a,b});
    }
    cout<<(int)loop.size()<<'\n';
    for(int i=0;i<(int)loop.size();i++){
        int a = loop[i].first;
        int p = find(a);
        int b = loop[i].second;
        // cout<<p<<" "<<a<<" "<<b<<'\n';
        for(int j=1;j<=n;j++){
            // cout<<j<<" from here i: "<<i<<endl;
            int k = find(j);
            // cout<<j<<" from later here i: "<<i<<endl;
            if(k != p){
                Union(k,p);
                cout<<a<<" "<<b<<" "<<a<<" "<<j<<'\n';
                break;
            }
        }
    }


    return 0;
    }