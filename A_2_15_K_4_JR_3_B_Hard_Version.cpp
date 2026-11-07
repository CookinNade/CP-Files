#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        ll arr[n];
        ll a=0,b=0;
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n,greater<int>());
        for(int i=0;i<n;i++){
            if(a<b){
                a += (1ll<<arr[i]);
            }
            else b += (1ll<<arr[i]);
        }
        cout<<a*b<<'\n';
    }
    return 0;
    }