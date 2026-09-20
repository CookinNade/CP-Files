#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    ll x,y;
    cin>>x>>y;
    ll tot = y*k + x;
    vector<ll>pref(n);
    for(int i=0;i<n;i++)cin>>pref[i];
    sort(pref.begin(),pref.end());
    for(int i=1;i<n;i++){
        pref[i] += pref[i-1];
    }

    ll arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    sort(arr,arr+m);
    ll sum = 0;
    ll ans = 0;
    auto it = upper_bound(pref.begin(),pref.end(),tot);
    if(it == pref.end()) ans = n;
    else{
        ll num = it - pref.begin();
        ans = max(ans , num);
    }
    // cout<<ans<<endl;
    ll cy = y;

    for(int i=0;i<m;i++){
        sum += arr[i];
        if(arr[i] > cy * k)break;
        ll kombe = arr[i] / k;
        if(arr[i] % k)kombe++;
        cy -= kombe;
        // cout<<cy<<" "<<kombe<<" "<<arr[i]<<" "<<sum<<endl;
        ll cnt = i+1;
        ans = max(ans, cnt);
        auto it = upper_bound(pref.begin(),pref.end(),tot-sum);
        if(it == pref.end())ans = (ans, cnt + n);
        else{
            int num = it - pref.begin();
            ans = max(ans , cnt + num);
        }
        // cout<<ans<<" "<<i<<endl;
    }
    cout<<ans;
    // cout<<fixed<<setprecision(20);
    // cout<<1e18<<endl;
    // cout<<1e18 + 1e15<<endl;
    return 0;
    }