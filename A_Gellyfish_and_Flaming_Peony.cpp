#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=5002;
ll dp[N-1][N];
ll n, gc, arr[N];
ll mamadpmar(ll m, ll g){
    if(g==1)return 0;
    if(m>=n)return 1000;
    if(dp[m][g]!=-1)return dp[m][g];
    ll ans=mamadpmar(m+1, g);
    if(g==5001)
    ans=min(ans,mamadpmar(m+1,arr[m])+1);
    else ans=min(ans,mamadpmar(m+1,gcd(g,arr[m]))+1);
    // cout<<ans<<" "<<m<<endl;
    return dp[m][g]=ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,m,a,b,c,d,cnt,r,l,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i==0)gc=arr[i];
            else gc=gcd(gc,arr[i]);
        }
        int yes=0;
        cnt=0;
        for(int i=0;i<n;i++){
            if(gc==arr[i])yes++;
            if(yes){
                for(int j=0;j<n;j++)if(arr[j]!=gc)cnt++;
            }
            if(yes)break;
        }
        if(yes){
            cout<<cnt<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            arr[i]=arr[i]/gc;
            // cout<<arr[i]<<" ";
        }
        // cout<<endl;
        // memset(dp,-1,sizeof(dp));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<N;j++)dp[i][j]=-1;
        }
        ll ans=mamadpmar(0,5001);
        // cout<<ans<<endl;
        cout<<ans+n-2<<endl;
    }
    return 0;
    }