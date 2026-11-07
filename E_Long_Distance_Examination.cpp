#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
struct coor{
    int i;
    int j;
    int x;
    int y;
    int cnt;
};
int r,c;
const int N = 101;
char a[N][N];
char b[N][N];
bool valid(int i, int j){
    if(i>=0 and i<r and j>=0 and j<c and a[i][j]!='X') return true;
    return false;
}
bool bvalid(int i, int j){
    if(i>=0 and i<r and j>=0 and j<c)return true;
    return false;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>r>>c;
        bool vis[r][c][r][c];
        memset(vis,false,sizeof vis);
        int ai,aj,bi,bj;
        for(int i=0;i<r;i++)for(int j=0;j<c;j++){
            cin>>a[i][j];
            if(a[i][j] == 'S')ai = i, aj = j;
        }
        for(int i=0;i<r;i++)for(int j=0;j<c;j++){
            cin>>b[i][j];
            if(b[i][j] == 'S')bi = i, bj = j;
        }
        // cout<<bi<<" "<<bj<<endl;
        queue<coor>q;
        q.push({ai,aj,bi,bj,0});
        vector<pair<int,int>>move;
        move.push_back({1,0});
        move.push_back({0,1});
        move.push_back({-1,0});
        move.push_back({0,-1});
        int ans = -1;
        while(!q.empty()){
            coor v = q.front();
            if(b[v.x][v.y] == 'D'){
                ans = v.cnt;
                break;
            }
            q.pop();
            // cout<<v.i<<" "<<v.j<<" "<<v.x<<" "<<v.y<<endl;
            if(vis[v.i][v.j][v.x][v.y])continue;
            vis[v.i][v.j][v.x][v.y] = true;
            for(auto c:move){
                if(valid(v.i + c.first, v.j + c.second)){
                    if(bvalid(v.x + c.first, v.y + c.second) and b[v.x + c.first][v.y + c.second]!='X')
                    q.push({v.i + c.first, v.j + c.second, v.x + c.first, v.y + c.second, v.cnt+1});
                    else q.push({v.i + c.first, v.j + c.second, v.x, v.y, v.cnt+1});
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
    }