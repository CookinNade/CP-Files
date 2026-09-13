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
        ll sum=0;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum=sum+arr[i];
        }
        sort(arr,arr+n);
        if(sum%2)sum= (sum/2) + 1;
        else sum=sum/2;
        ll ans=sum;
        // cout<<ans<<endl;
        for(int i=0;i<n;i++){
            sum=sum-arr[i];
            if(sum<0){
                ans++;
                ans=ans+n-i-1;
                break;
            }
            if(sum==0){
                ans=ans+n-1-i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    }