#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>s;
        cnt=0;
        ll pref[n];
        ll suff[n];
        ll step=0;
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                step=step+cnt;
                pref[i]=step;
            }
            else{
                cnt++;
                pref[i]=step;
            }
        }
        step=0; cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='.'){
                step=step+cnt;
                suff[i]=step;
            }
            else{
                cnt++;
                suff[i]=step;
            }
        }
        // for(int i=0;i<n;i++)cout<<pref[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<suff[i]<<" ";
        // cout<<endl;
        ll ans=1e18+10;
        for(int i=0;i<n;i++){
            ans=min(ans,pref[i]+suff[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
    }