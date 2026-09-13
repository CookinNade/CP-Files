#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
string s1,s2;
int dp[3005][3005];
int lcs(int i, int j){
    if(i<0 or j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    ans = max(ans,lcs(i-1,j));
    ans = max(ans,lcs(i,j-1));
    int f=0;
    if(s1[i]==s2[j])f++;
    ans =max(ans,lcs(i-1,j-1)+f);
    // cout<<ans<<" "<<i<<" "<<j<<endl;
    return dp[i][j]=ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    memset(dp,-1,sizeof(dp));
    cin>>s1>>s2;
    // cout<<s1.size()<<" "<<s2.size()<<endl;
    int i = s1.size(), j=s2.size();
    cout<<lcs(i-1,j-1)<<endl;
    return 0;
    }