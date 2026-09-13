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
        ll s=0,scnt=0;
        ll d=0,th=0;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a>=4){
                ans = ans + a;
                cnt++;
                s++;
                a = a-4;
                s += a/2;
            }
            else if(a==2){
                ans = ans+a;
                d++;
            }
            else if(a==3){
                ans += a;
                th++;
            }
            else scnt++;
        }
        // cout<<ans<<endl;
        if(d==1 and cnt==0 and scnt==0 and th==0){
            cout<<0<<endl;
            continue;
        }
        if(d==1 and cnt==0 and th==0)s++;
        if(d==0 and cnt==1 and th==0)s++;
        if(d==0 and cnt==0 and th==1)s++;
        ans += min(scnt , s);
        cout<<ans<<endl;
    }
    return 0;
    }