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
        cin>>n>>m>>k;
        ll mn = min(k-1,n-k);
        if(mn==0){
            ll ans = (m+1)/2;
            cout<<min(ans+1,n)<<endl;
            continue;
        }
        ll f = (m)/2;
        ll shuru = min(mn,((m+1)/3));
        ll time = m - 2*shuru +1;
        ll ans = (shuru+time)/2;
        ll anss = ans+shuru+1;
        cout<<min(anss,n)<<endl;
    }
    return 0;
    }