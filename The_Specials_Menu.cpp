#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll dp[61][61];
string s;
int n;
ll pali(int i, int j){
    
    if(i>=j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll way = 0;
    for(int l=i;l<j;l++){
        for(int r=j;r>l;r--){
            if(s[l] == s[r]) way = way + r - l + pali(l+1,r-1);
        }
    }
    return dp[i][j] = way;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt,k; 
    cin>>t;
    int tt = 1;
    
    while (t--){
        cout<<"Case "<<tt++<<": ";
        memset(dp,-1,sizeof dp);
        cin>>s;
        n = (int)s.size();
        cout<<pali(0,n-1) + n<<'\n';
    }
    return 0;
    }