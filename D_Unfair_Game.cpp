#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
long long nCk(ll n, ll k) {
    if (k > n) return 0;
    if (k > n - k) k = n - k;
    long long num = 1;
    for (int i = 1; i <= k; i++) {
        num=num * (n - i + 1) / i; 
    }
    return num;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        ll bit=0;
        a=1;
        while(a!=n){
            a=a*2;
            bit++;
        }
        ll pos = bit+1;
        ll ans=1;
        // cout<<bit<<endl;
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        if(k>=pos)ans++;
        for(ll i=bit-1;i>=1;i--){
            for(ll j=0;j<=i;j++){
                if(j+i+1<=k){
                    if(j==0)ans++;
                    else ans=ans+nCk(i,j);
                }
            }
        }
        cout<<n-ans<<endl;
    }
    return 0;
    }