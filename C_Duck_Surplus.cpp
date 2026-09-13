#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n-1;i++){
            ll a = arr[i];
            if(a>arr[i+1]) arr[i+1] = a + arr[i+1];
        }   
        cout<<arr[n-1]<<'\n';
    }
    return 0;
    }