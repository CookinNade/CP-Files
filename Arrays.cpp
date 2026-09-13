#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    const ll N=2e5+1;
    vector<int>g[n+1];
    for(int i=1;i<=n;i++){
        cin>>l;
        for(int j=0;j<l;j++){
            cin>>a;
            g[i].push_back(a);
        }
    }
    cin>>x>>k;
    cout<<g[x][k-1]<<endl;
    return 0;
    }