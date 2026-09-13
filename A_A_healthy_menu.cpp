#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n>>m;
    ll g[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    ll ans=0;
    for(int j=0;j<m;j++){
        cnt=0;
        for(int i=0;i<n;i++)cnt=max(cnt,g[i][j]);
        ans=ans+cnt;
    }
    cout<<ans<<endl;
    
    return 0;
    }