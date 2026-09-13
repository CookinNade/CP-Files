#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
map<ll,ll>dp;
ll ans;
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    ll arr[n];
    ll real;
    for(int i=0;i<n;i++){
        cin>>a;
        arr[i]=a;
        
        dp[a]=max(dp[a],dp[a-1]+1);
        if (ans<dp[a]){
            ans=dp[a];
            real=a;
        }   
    }
    cout<<ans<<endl;
    vector<ll>v;
    for(int i=n-1;i>=0;i--){
        if(arr[i]==real){
            real--;
            v.push_back(i+1);
        }
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    return 0;
    }