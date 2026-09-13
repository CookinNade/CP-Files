#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        x=__builtin_popcount(n);
        // cout<<x<<endl;
        if(x==1 or n==(1<<x)-1)cout<<-1<<endl;
        else{
            ll ans =0;
            int f=0; c=0; d=0;
            for(int i=29;i>=0;i--){
                if(((n>>i)&1) and f==0){
                    f++;
                    continue;
                }
                // if(i<=2)cout<<((n>>i)&1)<<" "<<i<<endl;
                if(((n>>i)&1)==1 and f and d==0){
                    ans=ans+(1ll<<i);
                    // cout<<i<<endl;
                    f++; d++;
                }
                if(f and ((n>>i)&1)==0 and c==0){
                    ans=ans+(1ll<<i);
                    c++;
                }
                if(d and c)break;
            }
            cout<<ans<<endl;
        }
        
    }
    return 0;
    }