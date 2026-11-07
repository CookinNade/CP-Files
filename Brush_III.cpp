#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 102;
int dp[N][N][N];
int w;
int d[N];
int n;
int dust(int i, int j, int k){
    if(i>n)return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];

    int ans = 0;
    
    if(j!=0 and d[j] + w >= d[i]){
        ans = 1 + dust(i+1,j,k);
        return dp[i][j][k] = ans;
    }

    if(k>0) ans = max(ans, 1 + dust(i+1,i,k-1));
    ans = max(ans, dust(i+1,j,k));
    
    return dp[i][j][k] = ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,k; 
    cin>>t;
    int tt = 1;
    while (t--){
        cout<<"Case "<<tt++<<": ";
        memset(dp,-1,sizeof(dp));
        cin>>n>>w>>k;
        // cout<<n<<w<<k;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            cin>>d[i];
        }
        sort(d+1,d+1+n);
        // for(int i=1;i<=n;i++)cout<<d[i]<<" ";
        cout<<dust(1,0,k)<<'\n';
    }
    return 0;
    }