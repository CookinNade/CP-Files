#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll dp[10][10];
ll d[10];
int n,m;
ll way(int i, int last){
    if(i == n)return 1;
    ll cnt = 0;
    if(i == 0){
        for(int j=0;j<m;j++){
            if(d[j] == 0)continue;
            cnt += way(i+1, d[j]);
        }
    }
    else{
        for(int j=0;j<m;j++){
            if(abs(d[j]-last) > 2)continue;
            cnt += way(i+1, d[j]);
        }
    }
    return dp[i][last] = cnt;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt,k; 
    int tt = 1;
    cin>>t;
    while (t--){
        cout<<"Case "<<tt++<<": ";
        cin>>m>>n;
        for(int i=0;i<m;i++)cin>>d[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = -1;
            }
        }
        cout<<way(0,0)<<'\n';
    }
    return 0;
    }