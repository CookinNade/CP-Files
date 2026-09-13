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
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++)cin>>arr[i];
    ll find = accumulate(arr,arr+n-1,0ll);
    ll sum = n*(n+1);
    ll rsum = sum/2;
    cout<<rsum-find<<endl;
    // }
    return 0;
    }