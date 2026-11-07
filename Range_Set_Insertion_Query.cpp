#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>g[m+1];
    for(int i=0;i<m;i++){
        int l,r,x;
        cin>>l>>r>>x;
        g[x].push_back({l,r});
    }
    int ans[n+2];
    fill(ans,ans+2+n,0);
    for(int i=1;i<=m;i++){
        if(g[i].empty())continue;
        // cout<<i<<" dhukse\n";
        sort(g[i].begin(),g[i].end());
        int l = g[i][0].first;
        int r = g[i][0].second;
        for(int j=0;j<(int)g[i].size();j++){
            if(r>=g[i][j].first) r = max(r,g[i][j].second);
            else{
                ans[l]++;
                ans[r+1]--;
                // cout<<l<<" "<<r<<" "<<i<<endl;
                l = g[i][j].first;
                r = g[i][j].second;
            }
        }
        // cout<<l<<" "<<r<<" "<<i<<endl;
        ans[l]++;
        ans[r+1]--;
    }
    // for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cnt+=ans[i];
        cout<<cnt<<" "; 
    }
    return 0;
    }