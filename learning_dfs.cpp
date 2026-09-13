#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int N=1e5+10;

vector<int> g[N];
int depth[N+1];int height[N+1];
void dfs(int vertex , int par){
    
}
vector<int> path(int node){
    vector<int>ans;
    while(node!=0){
        
        ans.push_back(node);
        node = height[node];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main () {
    int n,x,y;
    cin>>n;
    
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        g[x].push_back(y);  g[y].push_back(x);
    }
    dfs(1,0);
    cin>>x>>y;
    vector<int> p1 = path(x);
    vector<int> p2 = path(y);
    int lca;
    for(int i=0;i<min(p1.size(),p2.size());i++){
        if(p1[i]==p2[i]){
            lca=p1[i];
        }
        else break;
    }
    cout<<lca<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<depth[i]<<endl;
    // }cout<<endl;
    
    return 0;
    }