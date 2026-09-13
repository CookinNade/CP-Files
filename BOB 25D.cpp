#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    const ll N = 1e5 + 1;
    bool isntprime[N];
    fill(isntprime,isntprime+N,false);
    for(ll i = 2; i*i<= N; i++){
        if(!isntprime[i]){
            isntprime[i] = false;
            for(ll j = i*2; j<=N; j = j + i){
                isntprime[j] = true;
            }
        }
    }
    isntprime[1] = true;
    // for(int i=1;i<10;i++){
    //     if(!isntprime[i])cout<<i<<endl;
    // }
    while (t--){
        cin>>n;
        ll a[n+1];
        ll b[n+1];
        for(int i = 1; i<=n; i++) cin>>a[i];
        for(int i = 1; i<=n; i++) cin>>b[i];
        ll m = *max_element(b+1,b+n+1);
        ll ans = 0;
        int ind;
        // cout<<m<<endl;
        for(int i=1;i<=n;i++) if(b[i] == m){
            ind = i;
            break;
        }
        // cout<<ind<<endl;
        for(int i=1;i<ind;i++){
            ans += a[i];
            if(!isntprime[i]) ans += b[i];
            a[i+1] += b[i];
            // cout<<ans<<" "<<i<<" "<<a[i]<<" "<<a[i+1]<<endl;
        }
        for(int i=n;i>ind;i--){
            ans += a[i];
            if(!isntprime[i]) ans += b[i];
            a[i-1] += b[i];
            // cout<<ans<<" "<<i<<" "<<a[i]<<endl;
        }
        ans += a[ind];
        // cout<<ans<<endl;
        if(!isntprime[ind]) ans+=b[ind];

        cout<<ans<<endl;
    }
    return 0;
    }   