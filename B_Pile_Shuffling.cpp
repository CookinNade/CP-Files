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
        ll baki,req;
        ll ans=0;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c>>d;
            if(a>c){
                ans = ans + a-c;
                baki = c;
                if(b>d){
                    ans=ans+baki+b-d;
                }
            }
            else{
                if(b>d){
                    ans=ans+a+b-d;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    }