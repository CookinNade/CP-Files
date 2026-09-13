#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    const ll M = 998244353;
    while (t--){
        cin>>s;
        vector<ll>v;
        l=0;r=1;
        cnt=0;
        for(;r<s.size();r++,l++){
            if(r==s.size()-1){
                if(s[l]==s[r]){
                    cnt++; v.push_back(cnt);
                }
                else if(cnt==0) continue;
                else v.push_back(cnt);
            }
            else if(s[l]==s[r]) cnt++;
            else if(cnt==0 and s[l]!=s[r]) continue;
            else{
                v.push_back(cnt);
                cnt=0;
            }
        }
        r = accumulate(v.begin(),v.end(),0ll);
        ll n = r + v.size();
        ll ans =1;
        for(int i=1;i<=r;i++){
            ans=(ans*i)%M;
        }
        for(auto x:v){
            ans=(ans*(x+1))%M;
        }
        cout<<r<<" "<<ans<<endl;
    }
    return 0;
    }