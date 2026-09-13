#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e3+1;
bool vis[N][N];
char g[N][N];
int n,m;
void dfs(int i,int j){
    vis[i][j]=true;
    if(i+1<n and g[i+1][j]=='.' and vis[i+1][j]==false){
        dfs(i+1,j);
    }
    if(i-1>=0 and g[i-1][j]=='.' and vis[i-1][j]==false){
        dfs(i-1,j);
    }
    if(j+1<m and g[i][j+1]=='.' and vis[i][j+1]==false){
        dfs(i,j+1);
    }
    if(j-1>=0 and g[i][j-1]=='.' and vis[i][j-1]==false){
        dfs(i,j-1);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,d,cnt,r,l,k,x; 
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            vis[i][j]=false;
        }
    }
    for(int i=0;i<n;i++){
        if(g[i][0]=='.' and !vis[i][0])
        dfs(i,0);
    }
    for(int j=0;j<m;j++){
        if(g[0][j]=='.' and !vis[0][j])
        dfs(0,j);
    }
    for(int i=0;i<n;i++){
        if(g[i][m-1]=='.' and !vis[i][m-1])
        dfs(i,m-1);
    }
    for(int j=0;j<m;j++){
        if(g[n-1][j]=='.' and !vis[n-1][j])
        dfs(n-1,j);
    }
    cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='.' and !vis[i][j]){
                dfs(i,j);cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
    }