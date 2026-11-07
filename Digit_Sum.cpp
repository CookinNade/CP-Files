#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
string s;
ll d;
const int N = 10001;
ll dp[N][100][2];
int n;
const ll M = 1e9+7;
ll good(int i, int m, int yes){
    if(i == n){
        if(m)return 0;
        return 1;
    }
    if(dp[i][m][yes]!=-1)return dp[i][m][yes];
    ll way = 0;
    if(yes){
        for(int j=0;j<10;j++) way = (way + good(i+1, (m + j) % d, 1) % M) % M;
    }
    else{
        int c = s[i] - '0';
        for(int j=0;j<c;j++) way = (way + good(i+1, (m + j) % d, 1) % M) % M;
        way = (way + good(i+1, (m + c) % d, 0) % M) % M;
    }
    return dp[i][m][yes] = way % M;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>s>>d;
    memset(dp,-1,sizeof dp);
    n = (int)s.size();
    cout<<(good(0,0,0) - 1 + M) % M;
    return 0;
}