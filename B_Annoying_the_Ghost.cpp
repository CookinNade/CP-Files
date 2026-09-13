#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt; 
    cin>>t;
    while (t--){
        cin>>n;
        ll a[n];
        ll b[n];

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++)cin>>b[i];
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll num = b[i];
            int f = 0;
            for(int j=i;j<n;j++){
                if(num >= a[j]){
                    f++;
                    for(int k = j; k>i; k--){
                        swap(a[k],a[k-1]);
                        ans++;
                    }
                    break;
                }
                if(f) break;
            }
        }
        bool yes = true;
        for(int i=0;i<n;i++){
            if(b[i] >= a[i])continue;
            else yes = false;
        }
        if(yes)cout<<ans<<'\n';
        else cout<<-1<<'\n';

    }
    return 0;
    }