#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll m = arr[0];
        for(int i=0;i<n;i++){
            m = min(arr[i],m);
            arr[i] = m;
        }
        cout<<accumulate(arr,arr+n,0ll)<<endl;
    }
    return 0;
    }