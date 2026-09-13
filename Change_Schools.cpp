#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    // cin>>t;
    t = 1;
    while (t--){
        cin>>n>>k;
        ll arr[n] = {};
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr[a]++;
        }
        sort(arr,arr+n,greater<int>());
        int h = arr[0];
        int ans = 0;
        for(int i=0;i<n;i++){
            if(abs(h-arr[i]) <= 1)ans++;
        }
        cout<<ans;
    }
    return 0;
    }