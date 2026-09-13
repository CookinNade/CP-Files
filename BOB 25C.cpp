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
        int a[n];
        int b[n];
        for(int i=0; i<n; i++)cin>>a[i];
        for(int i=0; i<n; i++)cin>>b[i];
        int x = 0, y = 0;
        for(int i=0;i<n;i++)x = x ^ a[i];
        for(int i=0;i<n;i++)y = y ^ b[i];
        cnt = 0;
        for(int i = 31; i>=0; i--){
            if((x & (1<<i)) or (y & (1<<i)))cnt++;
        }
        cout<<((1ll<<cnt) - 1) * 2 <<endl;
    }
    return 0;
    }