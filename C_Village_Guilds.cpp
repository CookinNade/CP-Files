#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        int sz[n+1];
        int p[n+1];
        p[1] = 0;
        fill(sz,sz+n+1,0ll);
        for(int i=2;i<=n;i++){
            int a,b;
            cin>>a;
            p[i] = a;
            sz[a]++;
        }
        queue<int>q;
        pair<ll,ll> ans[n+1];

        for(int i=0;i<=n;i++){
            ans[i].first = 0;
            ans[i].second = 0;
        }

        for(int i=1;i<=n;i++)if(sz[i] == 0)q.push(i);
        // cout<<q.size()<<endl;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            if(v == 1)break;
            int par = p[v];
            sz[p[v]]--;
            if(sz[p[v]] == 0)q.push(p[v]);
            ll d = ans[v].first + 1ll;
            if(d>=ans[par].first){
                ans[par].second = ans[par].first;
                ans[par].first = d;
            }
            else if(d>ans[par].second){
                ans[par].second = d;
            }
        }
        ll sum = n;
        for(int i=1;i<=n;i++)sum+=ans[i].second;
        cout<<sum<<'\n';
    }
    return 0;
    }