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
        ll g[n+1][n+1];
        cnt=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=cnt;
                cnt++;
            }
        }
        ll real; ll ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                real=g[i][j];
                if(i-1>=1)real=real+g[i-1][j];
                if(i+1<=n)real=real+g[i+1][j];
                if(j+1<=n)real=real+g[i][j+1];
                if(j-1>=1)real=real+g[i][j-1];
                ans=max(real,ans);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    }