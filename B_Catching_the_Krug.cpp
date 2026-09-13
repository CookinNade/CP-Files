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
        ll kx,ky,dx,dy;
        cin>>kx>>ky>>dx>>dy;
        ll ans=-1;
        if(kx>dx){
            ans=max(ans,n-dx);
            // cout<<n-dx<<endl;
        }
        if(ky>dy){
            ans=max(ans,n-dy);
            // cout<<n-dy<<endl;
        }
        if(dy>ky){
            ans=max(ans,dy);
            // cout<<dy<<endl;
        }
        if(dx>kx){
            ans=max(ans,dx);
            // cout<<dx<<endl;
        }
        cout<<ans<<endl;

        
    }
    return 0;
    }