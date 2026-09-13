#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int col[n+1] , row[n+1];
    fill(col,col+n+1,0);
    fill(row,row+n+1,0);
    for(int i=0;i<m;i++){
        int c,r;
        cin>>r>>c;
        col[row[r]] = 0;
        row[col[c]] = 0;
        row[r] = c;
        col[c] = r;
    }
    int ans = 0;
    for(int i=1;i<=n;i++)if(col[i])ans++;
    cout<<ans;
    return 0;
    }