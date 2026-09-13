#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n+1];
        vector<ll>v;
        for(int i=1;i<=n;i++){
            
            cin>>arr[i];
        }
        cnt=1;
        v.push_back(1);
        for(ll i=2;i<=n;i++){
            
            if(arr[i]-arr[i-1]>=i){
                cnt++;
                v.push_back(cnt);
            }
            else{
                ll diff=arr[i]-arr[i-1];
                v.push_back(v[i-diff-1]);
            }
        }
        for(ll i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }cout<<endl;
    }
    return 0;
    }