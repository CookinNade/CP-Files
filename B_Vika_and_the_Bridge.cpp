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
        cin>>n>>k;
        map<int,vector<int>> mp;
        for(int i=1;i<=k;i++) mp[i].push_back(0);
        for(int i=1;i<=n;i++){
            cin>>a;
            mp[a].push_back(i);
        }
        int ans=1e9;
        for(int i=1;i<=k;i++) mp[i].push_back(n+1);
        for(int i=1;i<=k;i++){
            int max1=0;
            int max2=0;
            for(int j=0;j<mp[i].size()-1;j++){
                int del = mp[i][j+1]-mp[i][j]-1;
                if(del>max1){
                    swap(del,max1);
                    if(del>max2)swap(del,max2);
                }
                else if(del>max2) max2=del;
            }
            // cout<< "color #"<<i<< " and res: "<<max1<<" "<<max2<<endl;
            int mn = max(max1/2,max2);
            // cout<< "color #"<<i<< " and res: "<<max1<<" "<<max2<<" "<<mn<<endl;
            ans = min(ans,mn);
        }
        cout<<ans<<endl;
    }
    return 0;
    }