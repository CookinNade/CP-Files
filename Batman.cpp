#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
string a,b,c;
int m,n,o;
const int N = 51;
int dp[N][N][N];
int LCS(int i, int j, int k){
    if(i>=m)return 0;
    if(j>=n)return 0;
    if(k>=o)return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int ans = 0;
    if(a[i] == b[j] and b[j] == c[k])ans = max(ans, 1 + LCS(i+1,j+1,k+1));
    ans = max(ans, LCS(i+1,j,k));
    ans = max(ans, LCS(i,j+1,k));
    ans = max(ans, LCS(i,j,k+1));
    return dp[i][j][k] = ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    int tt = 1;
    while (t--){
        cout<<"Case "<<tt++<<": ";
        cin>>a>>b>>c;
        m = (int)a.size();
        n = (int)b.size();
        o = (int)c.size();
        memset(dp,-1,sizeof dp);
        cout<<LCS(0,0,0)<<'\n';
    }
    return 0;
    }