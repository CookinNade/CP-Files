#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 1001;
char g[N][N];
bool vis[N][N];
int n , m;
bool valid(int i , int j){
    if(i<n and i >= 0 and j < m and j >= 0) return true;
    return false;
}
void dfs(int i, int j){
    vis[i][j] = true;
    int x,y;
    x = i+1;
    y = j;
    if(valid(x,y) and g[x][y] == '.' and !vis[x][y]) dfs(x,y);
    x = i - 1;
    y = j;
    if(valid(x,y) and g[x][y] == '.' and !vis[x][y]) dfs(x,y);
    x = i;
    y = j + 1;
    if(valid(x,y) and g[x][y] == '.' and !vis[x][y]) dfs(x,y);
    x = i;
    y = j - 1;
    if(valid(x,y) and g[x][y] == '.' and !vis[x][y]) dfs(x,y);
    return;
}   
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt,k; 
    // cin>>t;
    t = 1;
    while (t--){
        cin>>n>>m;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                cin>>g[i][j];
                // cout<<g[i][j];
            }
            // cout<<'\n';
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j] == '.' and !vis[i][j]){
                    ans++;
                    dfs(i,j);
                }
            }
        }
        cout<<ans;

    }
    return 0;
    }