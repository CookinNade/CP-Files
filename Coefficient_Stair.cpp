#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
vector<vector<int>>v;
ll ans[11];
ll n;
void recur(ll mul , ll rem){
    if(mul == 1){
        vector<int>ansv;
        ans[1] = rem;
        for(int i=1;i<=n;i++)ansv.push_back(ans[i]);
        v.push_back(ansv);
        return;
    }
    ll k = rem / mul;
    for(;k>=0;k--){
        ll jabe = rem - k*mul;
        ans[mul] = k;
        recur(mul-1,jabe);
    }
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,cnt,k; 
    // cin>>t;
    t = 1;
    while (t--){
        ll sum;
        cin>>n>>sum;
        recur(n,sum);
        sort(v.begin(),v.end());
        for(auto vv : v){
            for(auto x : vv){
                cout<<x<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
    }