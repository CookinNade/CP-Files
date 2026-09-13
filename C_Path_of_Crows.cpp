#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 301;
vector<int>g[N];
struct item{
    int a;
    int b;
    int c;
};

bool vis[N];
void dfs(int ve, vector<item> &v){
    vis[ve] = true;
    for(auto c : g[ve]){
        if(ve == 2){
            dfs(c , v);
            continue;
        }
        if(vis[c])continue;
        else{
            v.push_back({c,ve,2});
            dfs(c, v);
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    
    while (t--){
        cin>>n;
        int p[n];
        for(int i=0;i<n;i++)cin>>p[i];
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        fill(vis+1,vis+n+1,false);
        vector<item>v;
        dfs(2 , v);
        int j;
        for(int i=0;i<n;i++) if(p[i]==2) j = i;
        for(int i = 0; i<=j-2; i++){
            int a = p[i+1];
            int b = p[i];
            v.push_back({b,2,a});
        }
        for(int i = n-1; i >=j+2; i--){
            int a = p[i-1];
            int b = p[i];
            v.push_back({b,2,a});
        }

        for(int i=1;i<=n;i++)g[i].clear();
        cout<<(int)v.size()<<'\n';
        for(auto x : v) cout<<x.a<<" "<<x.b<<" "<<x.c<<'\n';
        v.clear();

    }
    return 0;
    }