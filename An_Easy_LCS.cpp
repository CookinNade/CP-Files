#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 101;
string a,b;
int n,m;
int dp[N][N];
int nxta[N][26];
int nxtb[N][26];
int LCS(int i, int j){
    if(i>=n or j>=m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int len = 0;
    if(a[i]==b[j]){
        len = max(len, 1+LCS(i+1,j+1));
        return dp[i][j] = len;
    }
    len = max(len, LCS(i+1,j));
    len = max(len, LCS(i,j+1));
    return dp[i][j] = len;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt; 
    cin>>t;
    int tt = 1;

    while (t--){
        cout<<"Case "<<tt++<<": ";
        memset(dp,-1,sizeof(dp));
        cin>>a>>b;
        n = (int)a.size();
        m = (int)b.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<26;j++)nxta[i][j] = n;
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<26;j++)nxtb[i][j] = m;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<26;j++){
                nxta[i][j] = nxta[i+1][j];
            }
            nxta[i][a[i]-'a'] = i; 
        }
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<26;j++){
                nxtb[i][j] = nxtb[i+1][j];
            }
            nxtb[i][b[i]-'a'] = i; 
        }
        
        int i = 0;
        int j = 0;
        string ans = "";
        int rem = LCS(0,0);
        // cout<<rem<<endl;
        while(i<n and j<m){
            for(int k=0;k<26;k++){
                int ni = nxta[i][k];
                int nj = nxtb[j][k];
                if(ni == n or nj == m)continue;
                if(1 + LCS(ni+1,nj+1) == rem){
                    i = ni+1;
                    j = nj+1;
                    // cout<<ni<<" "<<nj<<" "<<(char)('a'+k)<<" "<<i<<" "<<rem<<endl;
                    rem--;
                    ans.push_back('a' + k); 
                    break;
                }
            }
            if(rem == 0) break;
        }
        if(ans.size()==0)cout<<":(\n";
        else cout<<ans<<'\n';
    }
    return 0;
    }