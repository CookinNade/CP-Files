#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n+1];
        for(int i=1;i<=n;i++) cin>>arr[i];
        cout<<1<<" ";
        ll l =1;ll r=2;
        for(;r<=n;r++){
            for(;l<=r;l++){
                if(l==r){
                    cout<<1<<" ";
                    break;
                }
                else if(arr[l]<r-l+1) continue;
                else if(arr[l]>=r-l+1){
                    cout<<r-l+1<<" ";
                    break;
                }
                
                else{
                    cout<<r-l+1<<" ";
                    break;
                }
            }
        }
        cout<<endl;      
    }
    return 0;
    }