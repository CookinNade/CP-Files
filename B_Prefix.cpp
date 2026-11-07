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
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll ans = arr[0];
        ll neg[n];
        for(int i=0;i<n;i++)neg[i] = arr[i];
        for(int i=1;i<n;i++){
            ll b = arr[0];
            for(int j=1;j<i;j++){
                b+=arr[j];
            }
            if(i==n-1){
                arr[i] = max(arr[i] - b, arr[i] + b);
                ans = max(arr[i],ans);
                break;
            }
            // cout<<b<<" "<<i<<endl;
            if(arr[i] + b < arr[i] - b){
                arr[i] += b;
            }
            else arr[i] -= b;
        }
        for(int i=1;i<n;i++){
            ll b = neg[0];
            for(int j=1;j<i;j++){
                b+=neg[j];
            }
            if(i==n-1){
                neg[i] = max(neg[i] - b, neg[i] + b);
                ans = max(neg[i],ans);
                break;
            }
            // cout<<b<<" "<<i<<endl;
            if(neg[i] + b > neg[i] - b){
                neg[i] += b;
            }
            else neg[i] -= b;
        }
        // for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        // cout<<endl;
        ans = max(*max_element(arr,arr+n),ans);
        ans = max(*max_element(neg,neg+n),ans);
        cout<<ans<<'\n';
    }
    return 0;
    }