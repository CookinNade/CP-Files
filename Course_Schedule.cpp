#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 1e5+1;
vector<int>g[N];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>topsort;
    queue<int>q;
    int incnt[n+1] = {};
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        incnt[b]++;
    }
    for(int i=1;i<=n;i++)if(incnt[i] == 0)q.push(i);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        topsort.push_back(v);
        for(auto c : g[v]){
            incnt[c]--;
            if(incnt[c] == 0)q.push(c);
        }
    }
    if((int)topsort.size() != n)cout<<"IMPOSSIBLE";
    else for(auto x:topsort)cout<<x<<" ";
    return 0;
    }