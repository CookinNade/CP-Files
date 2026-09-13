#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        ll cnt[n+1];
        fill(cnt+1,cnt+1+n,0);
        for(int i=0;i<n;i++){
            cin>>a;
            cnt[a]++;
        }
        ll suff[n+1];
        suff[n]=cnt[n];
        for(int i=n-1;i>=1;i--){
            suff[i]=cnt[i]+suff[i+1];
        }
        // for(int i=1;i<=n;i++)cout<<suff[i]<<" ";
        ll ans=1;
        for(ll i=1;i<=n;i++){
            c=cnt[i];
            if(i*4<=n)c=c+suff[i*4];
            for(int j=i*2;j<=n and j<i*4;j=j+i){
                c=cnt[j]+c;
            }
            if(c>=n-k)ans=max(ans,i);
        }
        cout<<ans<<endl;

        
    }
    return 0;
}