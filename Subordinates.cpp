#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 2e5+2;
int parent[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int cnt[n+1];
    fill(cnt,cnt+1+n,0);
    for(int i=2;i<=n;i++){
        cin>>parent[i];
        cnt[parent[i]]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)if(cnt[i] == 0)q.push(i);
    int ans[n+1];
    fill(ans,ans+1+n,0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        int p = parent[v];
        cnt[p]--;
        if(cnt[parent[v]] == 0)q.push(parent[v]);
        ans[p] = ans[p] + ans[v] + 1;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
    }