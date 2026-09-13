#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m;
        ll arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        vector<ll> real[m];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                real[i].push_back(arr[j][i]);
            }
        }
        // for(auto x:arr){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }cout<<endl;
        // }
        ll ans=0;
        for(auto x:real){
            sort(x.begin(),x.end());
            for(ll i=0;i<x.size();i++){
                ans = ans + x[i]*i - x[i]*(n-1-i);
            }
        }
        cout<<ans<<endl;

    }
    return 0;
    }