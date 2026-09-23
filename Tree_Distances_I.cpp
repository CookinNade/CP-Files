#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 2e5+2;
vector<int>g[N];
pair<int,int>mx1[N];
pair<int,int>mx2[N];
int p[N];
int ans[N];
int upor[N];
void dfs(int v){
    for(auto c:g[v]){
        if(c == 1 or p[c])continue;
        p[c] = v;
        dfs(c);
    }
}
void yo(int v){
    for(auto c:g[v]){
        if(c == p[v])continue;
        int val = 0;
        
        if(c!=mx1[v].second) val = mx1[v].first + 1;
        else val = mx2[v].first + 1;
        upor[c] = max(val, upor[v] + 1);
        
        int can1 = mx1[c].first;
        int can2 = upor[c];
        // cout<<c<<" "<<v<<" "<<mx1[c].first <<" "<< mx2[c].first<<" "<<upor[c]<<endl;
        ans[c] = max(can1,can2);
        yo(c);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int cnt[n+1];
    fill(cnt,cnt+1+n,0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    queue<int>q;
    for(int i=2;i<=n;i++){
        if(cnt[i] == 1)q.push(i);
    }
    // for(int i=1;i<=n;i++)cout<<mx1[i].first<<" "<<mx1[i].second<<'\n';
    dfs(1);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        int par = p[v];
        cnt[par]--;
        if(cnt[par] == 1)q.push(par);
 
        if(mx1[v].first + 1 > mx1[par].first){
            mx2[par].first = mx1[par].first;
            mx2[par].second = mx1[par].second;
            mx1[par].first = mx1[v].first + 1;
            mx1[par].second = v;
        }
        else if(mx1[v].first + 1 > mx2[par].first){
            mx2[par].first = mx1[v].first + 1;
            mx2[par].second = v;
        }
    }
    yo(1);
    // for(int i=1;i<=n;i++){
    //     cout<<i<<endl;
    //     cout<<mx1[i].first<<" "<<mx1[i].second<<endl;
    //     cout<<mx2[i].first<<" "<<mx2[i].second<<endl;
    // }
    // cout<<endl;
    ans[1] = mx1[1].first;
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
    }