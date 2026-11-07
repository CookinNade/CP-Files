#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 5000;
string a,b;
int n,m;
int dp[N][N];
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
    memset(dp,-1,sizeof(dp));
    cin>>a>>b;
    n = (int)a.size();
    m = (int)b.size();
    LCS(0,0);
    int i = 0;
    int j = 0;
    string ans = "";
    while(i<n and j<m){
        if(a[i] == b[j]){
            ans.push_back(a[i]);
            i++;
            j++;
        }
        else if(LCS(i+1,j) >= LCS(i,j+1))i++;
        else j++;
    }
    cout<<ans;
    return 0;
}