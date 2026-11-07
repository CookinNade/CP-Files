#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 3001;
ll dp[N][N];
int a[N];
int n;
ll f(int i, int j){
    if(i == j)return a[i];
    if(dp[i][j]!=-1)return dp[i][j];
    ll cnt = a[i] - f(i+1,j);
    cnt = max(a[j] - f(i,j-1), cnt);
    return dp[i][j] = cnt;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<f(0,n-1);
    return 0;
    }