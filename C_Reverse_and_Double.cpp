#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll ans = -1;
        int no = 0;
        for(int i=1;i<n;i++){
            if(abs(arr[i] - arr[i-1]) > ans){
                ans = abs(arr[i] - arr[i-1]);
                no = i-1;
            }
        }
        // cout<<no<<'\n';


        ll mx = 0;
        ll diff[n];
        diff[n-1] = 0;
        for(int i=0;i<n-1;i++){
            diff[i] = abs(arr[i] - arr[i+1]);
        }
        ll suff[n]; ll pref[n];
        fill(suff,suff+n,0ll); fill(pref,pref+n,0ll);

        for(int i=n-2;i>=0;i--){
            suff[i] = max(suff[i+1],diff[i]);
        }
        
        pref[0] = diff[0];
        for(int i=1;i<n;i++)pref[i] = max(pref[i-1],diff[i]);
        for(int i=no;i>=0;i--){
            if(i==no){
                ll bame = 0;
                ll dane = abs(arr[no]*2 - arr[no+1]);
                if(no!=0){
                    bame = abs(arr[no]*2 - arr[i-1]);
                }
                ll jabe = max(dane,bame);
                jabe = max(jabe, suff[no+1]);
                if(i>=2)jabe = max(jabe, pref[i-2]);
                ans = min(ans, jabe);
                // cout<<ans<<" "<<jabe<<" "<<mx<<endl;
                continue;
            }
            mx = max(mx,abs(arr[i] - arr[i+1]));
            ll dane = abs(arr[no+1]-2*arr[i]);
            ll bame = 0;
            if(i!=0)bame = abs(arr[no]*2 - arr[i-1]);
            ll jabe = max(dane, bame);
            jabe = max(jabe, suff[no+1]);
            if(i>=2)jabe = max(jabe, pref[i-2]);
            ans = min(ans, max(mx*2, jabe));
            // cout<<ans<<" "<<dane<<" "<<bame<<" "<<mx<<endl;
        }
        mx = 0;

        for(int i=no+1;i<n;i++){
            // cout<<i<<" this is i\n";
            if(i==no+1){
                ll bame = abs(arr[no] - 2*arr[no+1]);
                ll dane = 0;
                if(no+1!=n-1) dane = abs(2*arr[no+1] - arr[i+1]);
                ll jabe = max(dane,bame);
                if(no!=0) jabe = max(jabe, pref[no-1]);
                if(i!=n-1)jabe = max(jabe, suff[i+1]);
                ans = min(ans, jabe);
                continue;
            }
            mx = max(mx,abs(arr[i] - arr[i-1]));
            ll dane = 0;
            if(i!=n-1) dane = abs(2*arr[no+1]-arr[i+1]);
            ll bame = abs(arr[no] - 2*arr[i]);
            ll jabe = max(dane, bame);
            if(no!=0) jabe = max(jabe, pref[no-1]);
            if(i!=n-1)jabe = max(jabe, suff[i+1]);
            ans = min(ans, max(mx*2, jabe));
            // cout<<ans<<" "<<jabe<<" "<<mx<<endl;
        }
        cout<<ans<<'\n';
    }
    return 0;
    }