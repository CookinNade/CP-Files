#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3e3+1;
double dp[N][N];
double p[N];
int n;
double ase(int i, int j){
    // cout<<"dhukse "<<i<<" "<<j<<endl;
    int heads = j;
    int tails = i-j;
    if(i==n){
        if(heads>tails) return 1;
        return 0;
    }
    if(dp[i][j]!=-1.0)return dp[i][j];
    double h = p[i];
    double t = 1 - h;
    double way1 = 0;
    way1 = t * (ase(i+1,j));
    double way2 = 0;
    way2 = h * (ase(i+1,j+1));
    return dp[i][j] = way1 + way2;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cout<<fixed<<setprecision(9);
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j] = -1.0;
    
    for(int i=0;i<n;i++)cin>>p[i];
    cout<<ase(0,0);
    
}