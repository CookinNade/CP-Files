#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
    	ll a,b;
        cin>>n>>a>>b;
        if(3*a<b)cout<<n*a<<endl;
        else{
        	ll d = n/3;
        	ll ans = d*b;
        	ll x = n%3;
        	if(x*a<b) ans += x*a ;
        	else ans += b;
     		cout<<ans<<endl;
        }
    }
    return 0;
    }