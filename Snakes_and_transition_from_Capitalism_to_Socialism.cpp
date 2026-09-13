#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N = 2001;
const int INF = 2011;
int lev[N][N];
int g[N][N];
int n,m;

void reset(int n , int m){
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            lev[i][j]=INF;
        }
    }
}
int bfs(int mx){
    vector<pair<int,int>> move={{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1}};
    queue <pair<int,int>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]==mx){
                q.push({i,j});
                lev[i][j]=0;
            }
        }
    }
    int ans=0;
    while(!q.empty()){
        int cvx = q.front().first; int cvy = q.front().second;
        q.pop();
        for(auto mo: move){
            int changex= cvx+ mo.first; int changey=cvy+ mo.second;
            if(changex <1 or changey<1 or changex>n or changey>m or lev[changex][changey]!=INF) continue;
            lev[changex][changey]=lev[cvx][cvy]+1;
            ans = max(ans, lev[changex][changey]);
            q.push({changex,changey});
        }
    }
    return ans;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,a,b,c,d,cnt,r,l,k,x;
    reset(N,N);
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++){
    //         lev[i][j]=INF;
    //     }
    // }
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m;
        
        int mx=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>g[i][j];
                mx=max(mx,g[i][j]);
            }
        }
        cout<<bfs(mx)<<endl;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<lev[i][j]<<" ";
        //     }cout<<endl;
        // }
        
        reset(n,m);
    }
    return 0;
    }