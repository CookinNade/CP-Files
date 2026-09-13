#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1001;
char g[N][N];
bool vis[N][N];
pair<int,int>p[N][N];
int n , m;
bool hobe (int i , int j){
    if(g[i][j]=='.' or g[i][j] == 'B')return true;
    return false;
}
bool valid(int i , int j){
    
    if(i<n and i >= 0 and j < m and j >= 0 and hobe(i,j)) return true;
    return false;
}
char dig (int x,int y,int px, int py){
    if(px > x){
        return 'U';   
    }
    if(x > px){
        return 'D';
    }
    if(py > y){
        return 'L';
    }
    if(py < y){
        return 'R';
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt,k; 
    // cin>>t;
    t = 1;
    while (t--){
        cin>>n>>m;
        queue<pair<int,int>>q;
        pair<int,int>dest;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>g[i][j];
                if(g[i][j] == 'A')q.push({i,j});
                if(g[i][j] == 'B')dest = {i,j};
            }
        }
        int dx = dest.first;
        int dy = dest.second;
        // cout<<dx<<" "<<dy<<" this is destination "<<endl;
        int sx = q.front().first;
        int sy = q.front().second;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            // cout<<i<<" "<<j<<endl;
            if(q.front() == dest){
                vis[i][j] = true;
                break;
            }
            q.pop();
            int x,y;
            x = i+1;
            y = j;
            if(valid(x,y) and !vis[x][y]){
                vis[x][y] = true;
                p[x][y] = {i,j};
                q.push({x,y});
            }
            x = i - 1;
            y = j;
            if(valid(x,y) and !vis[x][y]){
                vis[x][y] = true;
                p[x][y] = {i,j};
                q.push({x,y});
            }
            x = i;
            y = j + 1;
            if(valid(x,y) and !vis[x][y]){
                vis[x][y] = true;
                p[x][y] = {i,j};
                q.push({x,y});
            }
            x = i;
            y = j - 1;
            if(valid(x,y) and !vis[x][y]){
                vis[x][y] = true;
                p[x][y] = {i,j};
                q.push({x,y});
            }
        }
        if(!vis[dx][dy]){
            cout<<"NO";
            return 0;
        }
        vector<char>v;

        while(true){
            if(dest.first == sx and dest.second == sy) break;
            int i = dest.first;
            int j = dest.second;
            v.push_back(dig(i,j,p[i][j].first,p[i][j].second));
            dest.first = p[i][j].first;
            dest.second = p[i][j].second;
        }
        cout<<"YES\n";
        cout<<(int)v.size()<<'\n';
        reverse(v.begin(),v.end());
        for(auto x:v)cout<<x;
    }
    return 0;
    }