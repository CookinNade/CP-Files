#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n>>k;
        if(k<n or k>=2*n){
            cout<<-1<<'\n';
            continue;
        }
        int g[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)g[i][j] = 0;
        }
        int mx = 2*n-1;
        int kom = mx - k;
        g[0][0] = 1;
        cnt = 2;
        for(int i=0;i<kom;i++){
            g[i+1][i+1] = cnt;
            cnt++;
        }
        for(int i=1;i<n;i++,cnt++)g[0][i] = cnt;
        for(int i=1;i<n;i++,cnt++)g[i][0] = cnt;    
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j])continue;
                g[i][j] = cnt;
                cnt++;
            }
        }    
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cout<<g[i][j]<<" ";
            cout<<'\n';
        }
        
    }
    return 0;
    }