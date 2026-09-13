#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N=8;
int vis[N][N]; int lev[N][N];
vector<int> g[N];
void reset(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            lev[i][j]=0; vis[i][j]=0;
        }
    }
}
int cx(string s1){
    return s1[0]-'a';
}
int cy(string s1){
    return s1[1]-'1';
}
vector <pair<int,int>>movements={{2,1},{2,-1},{1,2},{-1,2},{-1,-2},{1,-2},{-2,1},{-2,-1}};
int bfs(string s1,string s2){
    queue <pair<int,int>>q;
    int curx = cx(s1);
    int cury = cy(s1);
    int destx = cx(s2);
    int desty = cy(s2);
    q.push({curx,cury});
    vis[curx][cury]=1;
    lev[curx][cury]=0;
    while(!q.empty()){
        int hx = q.front().first;
        int hy = q.front().second;
        q.pop();
        for( auto move : movements){
            int move1 = move.first;
            int move2 = move.second;
            if(hx+move1 >7 or hx+move1 <0 or hy+move2 >7 or hy+move2<0 or vis[hx+move1][hy+move2])continue;
            vis[hx+move1][hy+move2]=1;
            lev[hx+move1][hy+move2]=lev[hx][hy]+1;
            q.push({hx+move1,hy+move2});
        }
        if(lev[destx][desty]!=1e9+10) return lev[destx][desty];
        // lev[hx][hy]=
    }

}

int main () {
    int n,x,y;
    string s1,s2;
    cin>>n;
    while(n--){
        cin>>s1>>s2;
        int destx = cx(s2);
        int desty = cy(s2);
        lev[destx][desty]=1e9+10;
        int ans = bfs(s1,s2);
        cout<<ans<<endl;
        reset();
    }
    return 0;
    }