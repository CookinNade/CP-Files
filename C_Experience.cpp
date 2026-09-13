#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2e5+2;
int sz[N];
int parent[N];
int point[N];
int find(int a){
    vector<int>v;
    v.clear();
    int sum = 0;
    while(a!=parent[a]){
        v.push_back(a);
        sum += point[a];
        a = parent[a];
    }
    sum += point[a];
    for(int i=0;i<(int)v.size();i++){
        int node = v[i];
        int pbf = point[node];
        point[node] =  sum - point[a];
        sum -= pbf;
        parent[node] = a;
    }
    return a;
}
void Union(int a , int b){
    if(sz[a] < sz[b]) swap(a,b);
    point[b] -= point[a];
    sz[a] += sz[b];
    parent[b] = a;
    return;
}
int get(int a){

}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        sz[i] = 1;
        parent[i] = i;
    }
    while(q--){
        string s;
        cin>>s;
        // cout<<s<<endl;
        if(s[0] == 'j'){
            int a,b;
            cin>>a>>b;
            int c = find(a);
            int d = find(b);
            if(c!=d)Union(c,d);
        }
        if(s[0] == 'a'){
            int a,p;
            cin>>a>>p;
            a = find(a);
            point[a] += p;
        }
        if(s[0] == 'g'){
            int a,b;
            cin>>a;
            b = find(a);
            if(a==b)cout<<point[a]<<'\n';
            else cout<<point[a] + point[b]<<'\n';
        }
    }

    return 0;
    }