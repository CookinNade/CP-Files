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
    ll prime [16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
    while (t--){
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll ans=-1;
        r=0;
        for(int j=0;j<16;j++){
            for(int i=0;i<n;i++){
                if(arr[i]%prime[j]!=0){
                    ans=prime[j]; r++;
                    break;
                }
            }
            if(r)break;
        }
        cout<<ans<<endl;
        
    }
    return 0;
    }