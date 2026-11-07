#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 1e5+2;
vector<int>g[N];
int cnt[N];
int dist[N];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fill(dist,dist+1+n,-1);
    fill(cnt,cnt+1+n,-1);
    dist[n] = 0;
    queue<int>q; q.push(n);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto c:g[v]){
            if(dist[c] == -1){
                dist[c] = dist[v] + 1;
                q.push(c);
            }
        }
    }
    int d = dist[1];

    q.push(1);
    cnt[1] = 0;
    bool yes = false;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto c:g[v]){
            if(cnt[c] == -1){
                cnt[c] = cnt[v] + 1;
                if(cnt[c] + dist[c] == d+1){
                    yes = true;
                    break;
                }
                q.push(c);
            }
            else{
                if(cnt[v] + dist[c] + 1 == d+1){
                    yes = true;
                    break;
                }
            }
        }
    }
    if(yes)cout<<"possible";
    else cout<<"impossible";

    return 0;
    }