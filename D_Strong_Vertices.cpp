#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        int a[n]; int b[n]; pair<int,int>ans[n]; vector<int>anss;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++) ans[i]={a[i]-b[i],i+1};
        sort(ans,ans+n,greater<pair<int,int>>());
        int mx=ans[0].first;
        for(int i=0;i<n;i++) if(ans[i].first==mx)anss.push_back(ans[i].second);
        sort(anss.begin(),anss.end());
        cout<<anss.size()<<endl;
        for(int i=0;i<anss.size();i++){
            cout<<anss[i]<<" ";
        }cout<<endl;
    }
    return 0;
    }