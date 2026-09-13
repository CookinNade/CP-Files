#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,q;
    cin>>n>>q;
    ll freq[33]={0};
    ll mx=-1;
    for(int i=0;i<n;i++){
        cin>>a;
        b=log2(a);
        freq[b]++;
        mx=max(mx,a);
    }
    while(q--){
        cin>>t;ll ans=0;
        for(int i=log2(mx);i>=0;i--){
            if(!freq[i] or (1ll<<i)>t) continue;

            if(freq[i]*(1ll<<i)<=t){
                ans=freq[i]+ans;
                t=t-freq[i]*(1ll<<i);
            }
            else if(freq[i]*(1ll<<i)>t and freq[i]>=t/(1ll<<i)){
                ans = ans + t/(1ll<<i);
                b= t/(1ll<<i);
                t=t-b*(1ll<<i);
            }
            if(!t)break;
        }
        if(!t)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
    }