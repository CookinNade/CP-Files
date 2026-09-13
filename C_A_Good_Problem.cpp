#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,w; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>l>>r>>k;
        double u;
        ll logr = log2(r-r%2);
        ll logl = log2(l);
        if(l==1){
            u =log2(l);
        }
        else u = log2(l);
        if(floor(u)==u){
            w = u+1;
        }
        else w=ceil(u);
        ll ans = 1ll<<w;
        if(n%2==1){
            cout<<l<<endl;
            // cout<<"it got here"<<endl;
        }
        else if(l==r or n==2 or ans>r){
            cout<<-1<<endl;
        }
        else if(n%2==0 and logr-logl==0)cout<<-1<<endl;
        else if(k<=n-2){
            cout<<l<<endl;
        }
        else cout<<ans<<endl;
        
    }
    return 0;
    }