#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 1e5+2;
vector<int>g[N];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int cnt[n+1];
    int dist[n+1];
    fill(cnt,cnt+1+n,0);
    fill(dist,dist+1+n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        cnt[b]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)if(cnt[i]==0)q.push(i);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto c:g[v]){
            cnt[c]--;
            if(cnt[c]==0){
                dist[c] = dist[v]+1;
                q.push(c);
            }
        }
    }
    cout<<*max_element(dist+1,dist+1+n);
    return 0;
    }