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
        ll arr[7];
        cnt=0;
        for(int i=0;i<7;i++){
            cin>>arr[i];
            cnt=cnt+arr[i];
        }
        ll ans=LLONG_MIN;
        for(int i=0;i<7;i++){
            ans=max(ans,2*arr[i]-cnt);
        }
        cout<<ans<<endl;
    }
    return 0;
    }