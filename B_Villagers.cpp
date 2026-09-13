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
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll ans=0;
        if(n%2==0){
            for(int i=0;i<n;i++){
                ans=arr[i+1]+ans;
                i++;
            }
        }
        else {
            ans=arr[0];
            for(int i=1;i<n;i++){
                ans=arr[i+1]+ans;
                i++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    }