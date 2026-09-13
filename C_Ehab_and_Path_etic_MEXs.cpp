#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b;
    cin>>n;
    vector<pair<ll,ll>>g[n+1];
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        g[a].push_back({b,i+1});
        g[b].push_back({a,i+1});
    }
    set<int>st;
    for(int i=1;i<=n;i++){
        if(g[i].size()==1)st.insert(g[i][0].second);
        // cout<<g[i].size()<<endl;
    }
    // cout<<st.size()<<endl;
    ll ans[n+1];
    int cnt=0;
    int m=n-2;
    for(int i=1;i<n;i++){
        if(st.find(i)!=st.end()){
            ans[i]=cnt;
            cnt++;
        }
        else {
            ans[i]=m;
            m--;
        }
    }
    for(int i=1;i<n;i++)cout<<ans[i]<<endl;
    return 0;
    }