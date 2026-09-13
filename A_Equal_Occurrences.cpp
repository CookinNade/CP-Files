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
        map<int,int>mp;
        map<int,int>mpp;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            mp[a]++;
        }
        
        int ans = 0;
        for(int i=1;i<=101;i++){
            int mx=0;
            for(auto it =mp.begin();it!=mp.end();++it){
                int itfirst= (*it).first;
                int itsecond = (*it).second;
                if(itsecond>=i){
                    mx=mx+i;
                }
                else continue;
            }
            ans=max(mx,ans);
        }
        cout<<ans<<endl;
        
    }
    return 0;
    }