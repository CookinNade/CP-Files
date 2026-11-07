#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,a,b;
    cin>>n>>a>>b;
    a = n - a - 1;
    cout<<abs(a-b)-1;

    return 0;
    }