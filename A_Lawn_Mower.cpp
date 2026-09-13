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
        ll ans=0;
        cin>>n>>k;
        ans = (n/k)*(k-1);
        ans=ans+(n%k);
        cout<<ans<<endl;
    }

    return 0;
    }