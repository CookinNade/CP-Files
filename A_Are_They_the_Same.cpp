#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n>>k;
        int a[n]; int b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        
        int acnt = 0;
        int bcnt = 0;
        for(int i=0;i<n;i++){
            if(a[i]%2)acnt++;
            if(b[i]%2)bcnt++;
        }
        if(acnt == bcnt)cout<<"YES\n";
        else if(acnt > bcnt){
            if(k%2)cout<<"NO\n";
            else cout<<"YES\n";
        }
        else{
            if(k%2)cout<<"YES\n";
            else cout<<"NO\n";
        }
        
    }
    return 0;
    }