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
        cin>>a>>b>>k;
        ll c = a & b;
        if(k == 1)cout<<a<<'\n';
        else if(k == 2)cout<<b<<'\n';
        else cout<< (c & b) <<'\n';
    }
    return 0;
    }