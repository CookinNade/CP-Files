#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int m,q,p;
        cin>>n>>m>>p>>q;
        if(n%p==0){
            if((n/p) * q == m)cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
    return 0;
    }