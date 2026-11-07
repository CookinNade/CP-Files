#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int even[n];
    fill(even,even+n,0);
    for(int i=0;i<n;i++)if(arr[i]%2==0)even[i]++;
    for(int i=1;i<n;i++)even[i]+=even[i-1];
    int ans = even[n-1];
    // for(int i=0;i<n;i++)cout<<even[i]<<" ";
    // cout<<endl;
    int suff[n];
    fill(suff,suff+n,0);
    for(int i=0;i<n;i++)if(arr[i]%2==0)suff[i]++;
    for(int i=n-2;i>=0;i--)suff[i]+=suff[i+1];
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=i;j<n;j++){
            if(arr[j]%2)cnt++;
            if(i!=0 and j!=n-1)ans = max(ans, cnt + even[i-1] + suff[j+1]);
            else if(i == 0 and j!=n-1) ans = max(ans,cnt + suff[j+1]);
            else if(i!=0 and j==n-1)ans = max(ans,cnt + even[i-1]);
            else ans = max(ans,cnt);
        }
    }
    cout<<ans;
    return 0;
    }