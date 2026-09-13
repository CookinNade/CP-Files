#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N=505;
char g[N][N];
ll cnt[N][N];
ll n,m,x,k,y;
void dfs(int i, int j){
    if(x==y-k)return;
    cnt[i][j]=1;
    x++;
    if(x==y-k)return;
    if(i!=0 and cnt[i-1][j]==0)dfs(i-1,j);
    if(j!=0 and cnt[i][j-1]==0)dfs(i,j-1);
    if(j!=m-1 and cnt[i][j+1]==0)dfs(i,j+1);
    if(i!=n-1 and cnt[i+1][j]==0)dfs(i+1,j);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    x=0;
    y=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            cnt[i][j]=0;
            if(g[i][j]=='.'){
                y++;
                cnt[i][j]=0;
            }
            else cnt[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(cnt[i][j]==0){
                dfs(i,j);
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(cnt[i][j]==0){
                cout<<'X';
            }
            else cout<<g[i][j];
        }
        cout<<endl;
    }
    
    return 0;
    }