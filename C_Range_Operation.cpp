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
    while (t--){
        cin>>n; ll mx=0; ll s = 0, mn = 0;
        for (int i = 1; i <=n; ++i) {
            int x;
            cin >> x;
            s += x;
            ll curr = (i ) * ll(i+1) - s;
            mn = min(mn, curr);
            mx = max(mx, curr-mn);
        }
        cout<<mx+s<<endl;

    }
    return 0;
    }