#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 301;
double dp[N][N][N];
int n;
double sushi(int i, int j, int k){
    if(i == 0 and j == 0 and k == 0)return 0;
    if(dp[i][j][k]!=-1.0)return dp[i][j][k];
    double x = n - i - j - k;
    double deno = n - x;
    double e = x;
    if(i>0)e = e + i*(1 + sushi(i-1,j,k));
    if(j>0)e = e + j*(1 + sushi(i+1,j-1,k));
    if(k>0)e = e + k*(1 + sushi(i,j+1,k-1));
    return dp[i][j][k] = e / deno;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=0;k<N;k++)dp[i][j][k]=-1.0;
    cin>>n;
    int one = 0;
    int two = 0;
    int three = 0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==1)one++;
        else if(a==2)two++;
        else three++;
    }
    // cout<<one<<" "<<two<<" "<<three<<endl;
    cout<<sushi(one,two,three);
    return 0;
    }