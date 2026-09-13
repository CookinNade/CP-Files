#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        n = 7;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[6] - arr[0] - arr[1]<<'\n';
    }
    return 0;
    }