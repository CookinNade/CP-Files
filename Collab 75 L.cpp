#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        vector<int> g[26];
        ll n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        for(int i=1;i<=n;i++){
            char c=s[i-1];
            g[c-'a'].push_back(i);
        }
        map<int,int>mp;
        for(int i=0;i<26;i++){
            if((int)g[i].size()<=1)continue;
            for(int j=0;j<g[i].size()-1;j++){
                if(g[i][j+1]-g[i][j]<=2){
                    mp[g[i][j]]=g[i][j+1];
                    char d =  'a'+i;
                    // cout<<d<<endl;
                    // cout<<g[i][j]<<" "<<g[i][j+1]<<endl;
                }
            }
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            if(r-l==1){
                cout<<"NO\n";
                continue;
            }
            auto it = mp.lower_bound(l);
            int a=(*it).first; int b= (*it).second;
            if(it!=mp.end() and a<=r and b<=r)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
    }