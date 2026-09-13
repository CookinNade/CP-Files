#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,y; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>x>>y;
        ll arr[n];
        ll ans[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++)ans[i]=(arr[i]/x)*y;
        ll tot = accumulate(ans,ans+n,0ll);
        cnt=0;
        for(int i=0;i<n;i++){
            d=tot-ans[i];
            cnt=max(cnt,d+arr[i]);
        }
        cout<<cnt<<endl;
    }
    return 0;
    }