#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        ll x,y,z;
        cin>>n>>x>>y>>z;
        ll ans = n / (x+y);
        if(n % (x+y))ans++;
        ll rem = n - z*x;
        ll time = z;
        if(rem>0){
            time += rem / (x + 10*y);
            if(rem % (x+10*y)) time++;
        }
        cout<<min(time, ans)<<'\n';
    }
    return 0;
    }