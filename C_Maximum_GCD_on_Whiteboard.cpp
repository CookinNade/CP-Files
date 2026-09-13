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
        cin>>n>>k;
        ll arr[n];
        ll fact[n+1];
        ll g[n+1];
        fill (g+1,g+1+n,0ll);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            a=arr[i];
            g[a]++;
            for(ll j=2;j*j<=a;j++){
                if(a%j==0){
                    x=a/j;
                    if((a/j)<=3)g[j]++;
                    if(x==j)continue;
                    else if((a/x)<=3)g[x]++;
                }
            }
        }
        sort(arr,arr+n);
        cnt=0;
        ll j=n; r=n-1;
        for(;j>=1;j--){
            for(;r>=0;r--){
                if(r==0)break;
                if(j*4<=arr[r]){
                    cnt++;
                }
                else{
                    fact[j]=cnt;
                    break;
                }
            }
            // cout<<r<<endl;
            if(r==0){
                for(;j>=0;j--){
                    if(j*4<=arr[0])fact[j]=cnt+1;
                    else fact[j]=cnt;
                }
            }
        }
        ll ans=1;
        for(ll i=1;i<=n;i++){
            if(fact[i]+g[i]>=n-k)
            ans=max(ans,i);
        }
        cout<<ans<<endl;

    }
    return 0;
    }