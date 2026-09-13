#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        int bit=0; a=1;
        while(a<n){
            a=a*2;
            bit++;
        }
        // cout<<bit<<endl;
        bit--;
        a=1;
        ll ans=0;
        for(int i=0;i<=bit+1;i++){
            ll num=(1ll<<i);
            if(num>n)continue;
            b = n/num;
            // if(b*num!=n)b++;
            // cout<<num<<" "<<b<<" "<<i<<endl;
            ans=ans+b;
        }
        // ans++;
        cout<<ans<<endl;
    }
    return 0;
    }