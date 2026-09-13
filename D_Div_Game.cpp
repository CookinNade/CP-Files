#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,cnt;
    ll ans=0;
    cin>>n;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            cnt=0;
            while(n%i==0){
                n=n/i;
                cnt++;
            }
            for(ll j=1;;j++){
                if(j<=cnt){
                    cnt=cnt-j;
                    ans++;
                }
                else break;
            }
        }
    }
    if(n>1)ans++;
    cout<<ans<<endl;
    return 0;
    }