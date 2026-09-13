#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k,a; 
    cin>>t;
    while (t--){
        cin>>n;
        ll ans = 0;
        cnt=0;
        int s=0,scnt=0;
        int d=0;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a>=4){
                ans = ans + a;
                cnt++;
                s++;
                a = a-4;
                s += a/2;
            }
            else if(a>=2){
                ans = ans+a;
                d++;
            }
            else scnt++;
        }
        // cout<<ans<<endl;
        if(d==0 and cnt==1)s++;
        if(d==1 and cnt==0 and scnt==0){
            cout<<0<<endl;
            continue;
        }
        if(d==1 and cnt==0)s++;
        ans += min(scnt , s);
        cout<<ans<<endl;
    }
    return 0;
    }