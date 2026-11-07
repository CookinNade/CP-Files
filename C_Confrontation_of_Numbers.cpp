#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int arr[n];
    int brr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++)cin>>brr[i];
    int suff[n+1];
    suff[n] = INT_MAX;
    for(int i=n-1;i>=0;i--)suff[i] = min(suff[i+1],brr[i]);
    int ans = min(suff[0],0);
    for(int i=0;i<n;i++)ans = max(min(arr[i],suff[i+1]), ans);
    cout<<ans;
    return 0;
    }