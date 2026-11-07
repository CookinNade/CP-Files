#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 51;
const ll M = 1e9+7;
ll n,k;
ll g[N][N];
void power(){
    ll new_g[n+1][n+1];
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)new_g[i][j] = 0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int p=1;p<=n;p++) new_g[i][p] = (new_g[i][p] + (g[i][j] * g[j][p]) % M) % M;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g[i][j] = new_g[i][j];
    return;
}
ll mexpo(ll kk){
    ll ans[n+1];
    fill(ans,ans+1+n,1);

    while(kk>0){
        if(kk%2){
            ll new_ans[n+1];
            fill(new_ans,new_ans+1+n,0);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    new_ans[i] = (new_ans[i] + (g[i][j] * ans[j]) % M) % M;
                }
            }
            for(int i=1;i<=n;i++)ans[i] = new_ans[i];
        }
        kk >>= 1;
        power();
    }
    ll cnt = 0;
    for(int i=1;i<=n;i++)cnt = (cnt + ans[i]) % M;
    return cnt;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) cin>>g[i][j];
    cout<<mexpo(k);
    return 0;
    }