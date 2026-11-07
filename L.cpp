
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll t=1;
    //cin>>t;
    while(t--){
       int n,m;
        cin>>n>>m;
        vector<int>g[m+1];
        vector<int>u[m+1];
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            g[v[i]].push_back(i);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(), v.end()),v.end());
        // for(auto x:v)cout<<x<<" ";
        // cout<<endl;
        for(int i = 0; i<(int)v.size();i++){
            int a = v[i];
            for(int j = g[a].size()-1;j>=0;j--){
                u[a].push_back(-g[a][j]);
            }
        }
        int ans = 0;
        for(int i=0;i<(int)v.size();){
            int a = v[i]; int l = g[a][0]; int r = u[a][0];
            int cntp = 1; int cntn = 1;

            for(int j = i+1;j<(int)v.size(); j++){
                int b = v[j];
                auto it = lower_bound(g[b].begin(),g[b].end(),l);
                if(it == g[b].end())break;
                else{
                    cntp++;
                    l = (*it);
                }
            }
            for(int j = i+1;j<(int)v.size(); j++){
                int b = v[j];
                auto it = lower_bound(u[b].begin(),u[b].end(),r);
                if(it == u[b].end())break;
                else{
                    cntn++;
                    r = (*it);
                }
            }
            // cout<<i<<" "<<cntp<<" "<<cntn<<'\n';
            ans++;
            int aga = max(cntp,cntn);
            i += aga;
        }
        cout<<(int)v.size()<<" "<<ans;
    }
}