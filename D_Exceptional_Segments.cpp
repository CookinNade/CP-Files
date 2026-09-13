#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M=998244353;
ll amount(ll n){
    if(n%2==0)n--;
    if(n<3)return 0;
    if(n==3)return 1;
    if(n%4==1){
        ll m = n/4;
        m=m%M;
        return (m*(m+1))%M;
    }
    if(n%4==3){
        ll m=n/4;
        m=m%M;
        ll ans=(m+1)%M;
        ans=(ans + (m*(m+1))%M)%M;
        return ans;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>x;
        ll first = amount(n);
        ll second = amount(x-1);
        ll third; 
        d=x;
        if(d%2) third = amount(n-d-1);
        else third = amount(n-d-2);
        // ll ans = first;
        ll ans= (first-second+M)%M;
        ans= (ans-third+M)%M;
        cout<<ans<<endl;
    }
    return 0;
    }