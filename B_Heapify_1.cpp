#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n+1];
        for(int i=1;i<=n;i++)cin>>arr[i];
        vector<ll>v;
        bool vis[n+1];
        fill(vis,vis+n+1,false);
        int no=0;
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            else{
                for(int j=i;j<=n;j=j*2){
                    // cout<<arr[j]<<endl;
                    v.push_back(arr[j]);
                    vis[j]=true;
                    
                }
                sort(v.begin(),v.end());
                for(int j=i,k=0;k<v.size();k++,j=j*2){
                    // cout<<j<<" "<<v[k]<<endl;
                    if(v[k]!=j){
                        no++;
                        break;
                    }
                }
                v.clear();
            }
        }
        if(no)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
    }