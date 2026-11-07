#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 1e9+7;
char g[1001][1001];
ll dp[1001][1001];
int r,c;
bool valid(int i, int j){
    if(i>=0 and j>=0 and i<r and j<c and g[i][j]!='#')return true;
    return false;
}

ll path(int i, int j){
    if(i==r-1 and j==c-1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    int way = 0;
    if(valid(i+1,j))way = path(i+1,j)%M;
    if(valid(i,j+1))way = (way + path(i,j+1)%M)%M;
    return dp[i][j] = way%M;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin>>r>>c;
    for(int i=0;i<r;i++)for(int j=0;j<c;j++)cin>>g[i][j];
    cout<<path(0,0);
    return 0;
    }