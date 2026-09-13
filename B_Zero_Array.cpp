#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    ll mx=*max_element(arr,arr+n);
    ll tot=accumulate(arr,arr+n,0ll);
    if(tot%2==0 and tot-mx>=mx)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
    }