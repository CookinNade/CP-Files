#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m;
        map<int,int>mp;
        vector<int> arr[n];
        for(int i=1;i<=m;i++)mp[i]=0;
        for(int i=0;i<n;i++){
            cin>>r;
            for(int j=0;j<r;j++){
                cin>>a;
                arr[i].push_back(a);
                mp[a]++;
            }
        }
        int yesser=0;
        
        for(int i=0;i<n;i++){
            int cnt = arr[i].size(); int ans=0;
            // cout<<ans<<" "<<cnt<<endl;
            for(int j=0;j<arr[i].size();j++){
                if(mp[arr[i][j]]>1)ans++;
            }
            if(ans==cnt){
                // cout<<i+1<<endl;
                // cout<<ans<<" "<<cnt<<endl;
                yesser++;
            }
        }
        
        int noer=1;
        for(auto it=mp.begin();it!=mp.end();++it){
            if((*it).second==0)noer=0;
        }
        // cout<<mp[5]<<endl;
        // cout<<yesser<<endl;
        if(noer and yesser>1)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }