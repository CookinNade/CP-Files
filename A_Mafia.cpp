#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n); ll big=arr[n-1];
    ll sum =accumulate(arr,arr+n,0ll);
    ll ans = sum/(n-1);
    if(sum%(n-1))ans++;
    cout<<max(big,ans)<<endl;
    return 0;
    }