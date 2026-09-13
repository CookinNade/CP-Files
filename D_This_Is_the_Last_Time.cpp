#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        int ans =k;
        map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            if(mp.find(a)!=mp.end()){
                if (mp[a].second<c) mp[a]={b,c};
                else if(mp[a].second==c and mp[a].first<b) mp[a]={b,c};
                continue;
            }
            mp[a]={b,c};
        }
        for(auto it =mp.begin();it!=mp.end();++it){
            if(k>=(it->first) and k<=(it->second.first) and k<=(it->second.second)){
                k=(it->second.second);
            }
            // cout<<(it->first)<<" "<<(it->second.first)<<" "<<(it->second.second)<<endl;
        }
        if(ans>k)cout<<ans<<endl;
        else cout<<k<<endl;
        
    }
    return 0;
    }