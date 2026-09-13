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
        map<ll,ll>mp;
        for(int i=0;i<n;i++){
            cin>>a;
            mp[a]++;
        }
        auto it = mp.begin();
        ll ans=-1;
        for(int i=0;i<k-1;i++){
            if(it==mp.end())break;
            if((*it).first-ans>1)break;
            else {
                ans++;
                ++it;
            }
            // cout<<ans<<endl;
        }
        cout<<ans+1<<endl;
    }
    return 0;
    }