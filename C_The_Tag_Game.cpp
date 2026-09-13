#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N= 2e5+10;

vector<int>g[N];
int allow[N+10];

int onedepth[N+10];
int twodepth[N+10];
void onedfs(int chi, int par){

    for(auto child:g[chi]){
        if(child==par)continue;
        onedepth[child]=onedepth[chi]+1;
        onedfs(child,chi);
    }
    
}
void twodfs(int chi, int par){
    for(auto child:g[chi]){
        if(child==par)continue;
        twodepth[child]=twodepth[chi]+1;
        twodfs(child,chi);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n>>x;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        g[a].push_back(b); g[b].push_back(a);
    }
    onedfs(1,0);
    twodfs(x,0);
    int ans=-1;
    for(int i=2;i<=n;i++){
        if(g[i].size()==1 and onedepth[i]>twodepth[i]) ans = max(ans,onedepth[i]);
    }
    if(ans==-1){
        cout<<onedepth[x]*2<<endl;
    }
    else cout<<ans*2<<endl;


    return 0;
    }