#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        n = (int)s.size();
        ll p[n];
        ll sf[n];
        fill(p,p+n,0ll);
        fill(sf,sf+n,0ll);
        for(int i = 0;i<n;i++){
            if(s[i]=='2')p[i]++;
            if(i!=0)p[i] = p[i-1] + p[i];
        }
        for(int i = n-1; i>=0; i--){
            if(s[i]=='1' or s[i]=='3')sf[i]++;
            if(i!=n-1)sf[i] = sf[i+1] + sf[i];
        }
        // for(auto x : p)cout<<x<<" ";
        // cout<<endl;
        // for(int i=n-1;i>=0;i--)cout<<sf[i]<<" ";
        ll ans = max(sf[0] , p[n-1]);
        for(int i=0;i<n-1;i++){
            ans = max(ans , sf[i+1] + p[i]);
        }
        cout<<n-ans<<endl;

    }
    return 0;
    }