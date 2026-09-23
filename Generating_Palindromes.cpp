#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int dp[101][101][101];
string s;        
int n;
const int INF = 908;
int kalo(int i, int use, int back){
    // cout<<i<<'\n';
    if(i>=n)return 0;
    int j = n-1 - i + use - back;
    if(i >= j)return 0;
    if(dp[i][use][back] != -1) return dp[i][use][back];
    int ans = INF;
    ans = min(ans, 1 + kalo(i+1, use+1, back));
    ans = min(ans, 1 + kalo(i, use, back+1));
    if(s[i] == s[j])ans = min(ans, kalo(i+1,use,back));
    // cout<<i<<" "<<j<<endl;
    return dp[i][use][back] = ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt,k; 
    cin>>t;
    int tt = 1;
    while (t--){
        cout<<"Case "<<tt++<<": ";
        memset(dp,-1,sizeof(dp));
        cin>>s;
        n = (int)s.size();
        cout<<kalo(0,0,0)<<'\n';
    }
    return 0;
    }