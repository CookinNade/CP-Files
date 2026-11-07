#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 2e5+2;
vector<int>b[N];
vector<int>g[N];
int bands[N];
int fans[N];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,c;
    cin>>n>>m>>c;
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        fans[i] = k;
        for(int j=0;j<k;j++){
            int a;
            cin>>a;
            g[i].push_back(a);
            b[a].push_back(i);
            bands[a]++;
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++) if(bands[i] < c) q.push(i);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto f:b[v]){
            fans[f]--;
            if(fans[f]*2 >= (int)g[f].size())continue;
            else if((fans[f] + 1)*2 < (int)g[f].size())continue;
            else{
                for(auto band : g[f]){
                    bands[band]--;
                    if(bands[band]+1 == c) q.push(band);
                }
            }
        }
    }
    vector<int>ans;
    for(int i=1;i<=n;i++) if(bands[i] >= c) ans.push_back(i);
    if(ans.empty())cout<<"impossible";
    else{
        cout<<"possible\n";
        cout<<(int)ans.size()<<'\n';
        for(auto x:ans)cout<<x<<" ";
    }
    return 0;
    }