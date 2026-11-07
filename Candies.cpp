#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 1e9+7;
const int N = 1e5+2;
int n;
ll dp[101][N];
ll a[101];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<=a[0];i++)dp[0][i] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            if(j==0)dp[i][j] = 1;
            else {
                ll last = j - a[i] - 1;
                if(last>=0)dp[i][j] = (dp[i][j-1] +  (dp[i-1][j] - dp[i-1][last] + M) % M) % M;
                else dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % M;
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=k;j++)cout<<dp[i][j]<<" ";
    //     cout<<'\n';
    // }
    cout<<dp[n-1][k]%M;
    return 0;
    }