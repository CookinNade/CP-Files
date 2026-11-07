#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n>>k;
        ll ans = (1ll << (n-k+1));
        for(int i=0;i<k-1;i++)ans+=2;
        cout<<ans<<'\n';        
    }
    return 0;
    }