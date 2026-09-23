#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int a,b,c;
        cin>>a>>b>>c;
        cout<<n-min(a,min(b,c))<<'\n';
    }
    return 0;
    }