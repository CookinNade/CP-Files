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
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        if(n%2){
            cout<<"NO\n";
            continue;
        }
        int mx = 0;
        int mn = 1e9 + 2;
        for(int i=0;i<n;i++){
            if(i%2==0){
                mn = min (mn , arr[i] - 1);
            }
            else mx = max(mx, arr[i] + 1);
        }
        if(mn>=mx)cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    return 0;
    }