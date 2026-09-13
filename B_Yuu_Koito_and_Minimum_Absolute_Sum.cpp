#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>a>>b>>m;
    ll ans=1;
    int i=0;
    while(b){
        if(b&1)ans=(ans*a)%m;
        a=(a*a)%m;
        b=b>>1;
        cout<<a<<" "<<ans<<" for the bit #"<<i<<endl;
        i++;
    }
    cout<<ans<<endl;
    return 0;
    }