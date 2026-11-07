#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

ll n,k;
double dp[401][401];
double f(int h, int rem){
    if(rem == 0)return h;
    if(dp[h][rem]!=-1)return dp[h][rem];
    double tot = 0;
    if(h == n){
        tot += 0.5 * (double)f(h-1, rem-1);
        tot += 0.5 * (double)f(h, rem-1);
    }   
    else{
        tot += 0.5 * (double)f(h+1, rem-1);
        tot += 0.5 * (double)f(h, rem-1);
    }
    return dp[h][rem] = tot;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    cout<<fixed<<setprecision(10);
    for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)dp[i][j] = -1.0;
    double heads = f(0,k);
    cout<<heads;
    return 0;
    }