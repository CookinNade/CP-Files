#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll M = 998244353;
const int N = 2e5+10;
ll dp[N][3][2];
ll arr[N];
int n;
ll f(int i, int j, int k){
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    ll ans = 0;
    if(j == 0){
        for(int l=i+1;l<n;l++){
            if(arr[i] + 1 == arr[l] or arr[i] + 2 == arr[l]) {
                ans = (ans + 1 + f(l,arr[l] - arr[i],0)) % M;
                // if(arr[i] == 1) cout<<f(l,arr[l] - arr[i],0) + 1<<" ff "<<arr[l]<<endl;
            }
            else{
                ans = (ans + n - l + M) % M;
                break;
            }
        }
    }
    if(j == 1){
        // if(k == 1){
        //     cout<<"1 = k "<<arr[i]<<endl;
        // }
        for(int l=i+1;l<n and l<i+3;l++){
            if(arr[i] + 1 == arr[l] and k!=1) {
                ans = (ans + 1 + f(l,arr[l]-arr[i],1)) % M;
                
            }
            if(arr[i] + 2 == arr[l]) {
                ans = (ans + 1 + f(l,arr[l]-arr[i],0)) % M;
                
            }
        }
    }
    if(j == 2){
        
        for(int l=i+1;l<n and l<i+3;l++){
            if(arr[i] + 1 == arr[l]){
                ans = (ans + 1 + f(l,arr[l]-arr[i],0)) % M;   
            }
        }
    }
    return dp[i][j][k] = ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,cnt; 
    cin>>t;
    while (t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            for(int j=0;j<3;j++) for(int k=0;k<2;k++) dp[i][j][k] = -1;
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            ans = (ans + f(i,0,0)) % M;
            // cout<<i<<" "<<f(i,0,0)<<" \n";
        }
        cout<<(ans + n) % M<<'\n';
    }
    return 0;
    }