#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>s;
        int yes=0; cnt=0;
        vector<ll>v;
        for(int i=0;i<n;i++)if(s[i]=='1')cnt++;
        if(cnt==n)cout<<0<<endl;
        else{
            for(int i=0;i<n;i++){
                if(s[i]=='1')v.push_back(i);
            }
            ll ans=0;
            for(int i=0;i<n;i++){
                
                if(s[i]=='0'){
                    auto it = upper_bound(v.begin(),v.end(),i);
                    if(it == v.end()){
                        auto it = lower_bound(v.begin(),v.end(),0);
                        ans =max(ans,n-i+(*it));
                    }
                    else {
                        ans=max(ans,(*it)-i);
                    }
                }
            }
            cout<<ans<<endl;

        }
    }
    return 0;
    }