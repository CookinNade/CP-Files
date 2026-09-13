#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    // cin>>t;
    // string s;
    // while (t--){
        
    // }
    cin>>n;
    ll arr[n];
    ll sum=0;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            sum = sum+abs(arr[i-1]-arr[i]);
            arr[i]=arr[i-1];
        }
    }
    cout<<sum<<endl;
    return 0;
    }