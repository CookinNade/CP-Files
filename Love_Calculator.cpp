#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int n;
int m;
pair<int,ll> dp[31][31];
string a,b;
pair<int,ll>ways(int i, int j){
    if(i == n and j == m)return {0,1};
    if(dp[i][j].first!=-1 and dp[i][j].second!=-1)return dp[i][j];
    pair<int,ll>ans = {n+m+5,0};
    pair<int,ll>tc;
    if(i!=n and j!=m and a[i] == b[j]){
        tc = ways(i+1, j+1);
        if(tc.first < ans.first)ans = tc;
        else if(tc.first == ans.first)ans.second += tc.second;
        ans.first++;
        return dp[i][j] = ans;    
    }
    if(i!=n){
        tc = ways(i+1, j);
        if(tc.first < ans.first)ans = tc;
        else if(tc.first == ans.first)ans.second += tc.second;
    }
    if(j!=m){
        tc = ways(i, j+1);
        if(tc.first < ans.first)ans = tc;
        else if(tc.first == ans.first)ans.second += tc.second;
    }
    ans.first++;
    return dp[i][j] = ans;
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
        cin>>a>>b;
        n = (int)a.size();
        m = (int)b.size();
        pair<int,ll> ans = ways(0,0);
        cout<<ans.first<<" "<<ans.second<<'\n';
    }
    return 0;
    }