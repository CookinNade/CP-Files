#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
const int N=1e5+10;
vector <pair<ll,ll>> g[N];
ll lev[N];
ll wt[N];
void reset(int n){
    for(int i=1;i<=n;i++){
        g[i].clear();
    }   
}
void bfs(ll v){
    queue<ll>q;
    q.push(v);
    lev[v]=0;
    wt[v]=0;
    while(!q.empty()){
        ll cv=q.front();
        q.pop();
        
        for(auto child:g[cv]){
            ll childv = child.first;
            // cout<<childv<<" "<<wt[childv]<<" "<<cv<<endl;
            if(wt[childv]>=0)continue;
            
            lev[childv]=lev[cv]+1;
            q.push(childv);
            wt[childv]=wt[cv]+lev[childv]*child.second;
            
        }
    }

}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        fill(wt, wt + N, -1);
        vector<ll>spec;
        cin>>n>>m;
        map<ll,ll> mp;
        for(int i=0;i<m;i++){
            cin>>a;
            mp[a]++;
        }
        for(int i=0;i<n-1;i++){
            cin>>a>>b>>x;
            g[a].push_back({b,x}); g[b].push_back({a,x});
        }
        bfs(1ll);
        
        for(ll i=2;i<=n;i++){
            if(g[i].size()==1) spec.push_back(wt[i]);
        }
        cnt=0;
        sort(spec.begin(),spec.end());
        for(int i=0;i<spec.size();i++){
            auto it = mp.lower_bound(spec[i]);
            if(it==mp.end())break;
            else{
                cnt++;
                ll itfirst = (*it).first;
                mp[itfirst]--;
                if((*it).second==0)mp.erase(itfirst);
            }
        }
        // for(int i=1;i<=n;i++){
        //     cout<<wt[i]<<" ";
        // }cout<<endl;
        // for(int i=0;i<spec.size();i++){
        //     cout<<spec[i]<<" ";
        // }cout<<endl;
        // for(int i=1;i<=n;i++){
        //     cout<<lev[i]<<" ";
        // }
        // cout<<endl;

        fill(wt, wt + n, -1);
        cout<<cnt<<endl;
        reset(n);
        
    }
    return 0;
    }