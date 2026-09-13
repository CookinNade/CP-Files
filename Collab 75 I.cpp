#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c;
    cin>>a>>b>>c;
    map<ll,ll>mpb;
    map<ll,ll>mpc;
    ll n=b;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n=n/i;
            }
            mpb[i]=cnt;
        }
    }
    if(n!=1)mpb[n]=1;

    n=c;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n=n/i;
            }
            mpc[i]=cnt;
        }
    }
    if(n!=1)mpc[n]=1;
    ll m=c-1;
    bool yes=true;
    for(auto it=mpb.begin();it!=mpb.end();++it){
        ll x = (*it).first; ll y = (*it).second; 
        // cout<<x<<" "<<y<<endl;
        if(mpc.find(x)!=mpc.end() and y*m == mpc[x])continue;
        else {
            yes=false;
            break;
        }
    }
    if(yes)cout<<"What an excellent example!";
    else cout<<"Oh look, a squirrel!";
    return 0;
    }