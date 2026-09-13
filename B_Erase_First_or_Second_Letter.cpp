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
        set<char>st;
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(st.find(s[i])!=st.end())continue;
            st.insert(s[i]);
            ans=n-i-1 + ans;
        }
        cout<<ans+st.size()<<endl;
    }
    return 0;
    }