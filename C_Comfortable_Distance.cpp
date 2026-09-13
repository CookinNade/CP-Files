#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,d,cnt,r,l,k,x; 
    // cin>>t;
    t=1;
    string s;
    while (t--){
        cin>>n>>l>>r;
        cin>>s;
        vector<ll>g[26];
        for(int i=0;i<n;i++){
            g[s[i]-'a'].push_back(i);
        }
        ll ans=0;
        for(int i=0;i<26;i++){
            if(g[i].size()<=1)continue;
            for(int j=0;j<g[i].size()-1;j++){
                a=g[i][j];
                auto lit= lower_bound(g[i].begin(),g[i].end(),a+l);
                auto rit= upper_bound(g[i].begin(),g[i].end(),a+r);
                rit--;
                if(lit==g[i].end())continue;
                if(*lit>*rit)continue;
                ans=ans+(rit-lit)+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    }