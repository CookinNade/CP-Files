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
        cin>>n;
        map <int,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            if(mp.find(a)==mp.end()){
                mp[a].first=b;
                mp[a].second=i+1;
            }
            else {
                if(mp[a].first<b){
                    mp[a].first=b;
                    mp[a].second=i+1;
                }
            }
        }
        cout<<mp.size()<<endl;
        for(auto it = mp.begin();it!=mp.end();++it){
            cout<<(*it).second.second<<" ";
        }cout<<endl;
    }
    return 0;
    }