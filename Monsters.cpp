#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1001;
bool vis[N][N];
int dist[N][N];
int dis[N][N];
char shora[N][N];
char g[N][N];
int n,m;

bool hobe(int i, int j){
    if(i >=0 and i<=n-1 and j>=0 and j<=m-1 and g[i][j]!='#' and !vis[i][j])return true;
    return false;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    queue<pair<pair<int,int>,int>>q;
    int ax , ay;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j] = 1e6;
            dis[i][j] = 1e7;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j] == 'M'){
                q.push({{i,j},0});
                vis[i][j] = true;
                dist[i][j] = 0;
            }
            else vis[i][j] = false;
            if(g[i][j]=='A'){
                ax = i;
                ay = j;
                dis[i][j] = 0;
            }
        }
    }
    vector<pair<int,int>>move;
    move.push_back({1,0});
    move.push_back({-1,0});
    move.push_back({0,1});
    move.push_back({0,-1});
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int d = q.front().second;
        q.pop();
        for(auto moves : move){
            int x = moves.first + i;
            int y = moves.second + j;
            if(hobe(x,y)){
                q.push({{x,y},d+1});
                vis[x][y] = true;
                dist[x][y] = d+1;
            }
        }
    }
    q.push({{ax,ay},0});
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)vis[i][j] = false;
    vis[ax][ay] = true;
    while(!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int d = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            pair<int,int> moves = move[k];
            int x = moves.first + i;
            int y = moves.second + j;
            // cout<<x<<" "<<y<<" "<<i<<" "<<j<<endl;
            if(hobe(x,y)){
                q.push({{x,y},d+1});
                vis[x][y] = true;
                dis[x][y] = d+1;
                if(k == 0)shora[x][y] = 'D';
                if(k == 1)shora[x][y] = 'U';
                if(k == 2)shora[x][y] = 'R';
                if(k == 3)shora[x][y] = 'L';
            }
        }
    }
    bool yes = false;
    int tx,ty;
    for(int j=0;j<m;j++){
        if(dist[0][j]> dis[0][j]){
            yes = true;
            tx = 0; ty = j;
            break;
        }
        if(dist[n-1][j]> dis[n-1][j]){
            yes = true;
            tx = n-1; ty = j;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i][0]> dis[i][0]){
            yes = true;
            tx = i; ty = 0;
            break;
        }
        if(dist[i][m-1]> dis[i][m-1]){
            yes = true;
            tx = i; ty = m-1;
            break;
        }
    }
    if(!yes){
        cout<<"NO\n";
        return 0;
    }
    vector<char>v;
    while(true){
        if(tx==ax and ty == ay)break;
        char c = shora[tx][ty];
        v.push_back(c);
        if(c == 'D')tx--;
        if(c == 'U')tx++;
        if(c == 'R')ty--;
        if(c == 'L')ty++;
    }
    cout<<"YES\n";
    cout<<(int)v.size()<<'\n';
    reverse(v.begin(),v.end());
    for(auto x:v)cout<<x;

    return 0;
    }