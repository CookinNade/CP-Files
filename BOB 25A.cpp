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
        if(n%2)cout<<n/2 + 1<<endl;
        else cout<<n/2<<endl;
    }
    return 0;
    }   