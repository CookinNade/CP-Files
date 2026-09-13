#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        ll a,b;
        cin>>a>>b;
        if(a%b==0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }