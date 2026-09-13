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
        ll a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        ll m = *max_element(a,a+n);
        int ind = -1;
        for(int i=0;i<n;i++){
            if(a[i] == m){
                ind = i; 
                break;
            }
        }
        ll x = a[0];
        for(int i=0; i<ind ; i++){
            x = max(x, a[i]);
            a[i] = x;
        }
        x = a[n-1];
        for(int i=n-1; i>ind ; i--){
            x = max(x, a[i]);
            a[i] = x;
        }
        cout<<accumulate(a,a+n,0ll)<<endl;
        
    }
    return 0;
    }