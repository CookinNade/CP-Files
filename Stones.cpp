#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 1e5+2;
short dp[N];
int v[100];
int n;
short stones(int k){
    if(dp[k]!=-1)return dp[k];
    short way = 1;
    for(int i=0;i<n;i++){
        if(k>=v[i])way *= stones(k-v[i]);
    }
    if(way)return dp[k] = 0;
    else return dp[k] = 1;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin>>n>>k;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)cin>>v[i];
    if(stones(k))cout<<"First";
    else cout<<"Second";
    return 0;
    }