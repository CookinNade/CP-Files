#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n);
        int curr = 1;
        int mx = 1;
        for(int i=1;i<n;i++){
            if(arr[i] - arr[i-1] <=1){
                curr++;
                mx = max(curr,mx);
            }
            else curr = 1;
        }
        cout<<n-mx<<'\n';
    }
    return 0;
    }