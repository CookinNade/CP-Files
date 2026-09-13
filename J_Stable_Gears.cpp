#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void print(__int128 x) {
    if (x > 9) print(x / 10);
    cout<<char(x % 10 + '0');
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin >> n;
        __int128 b = (__int128)n * n;
        print(b/4);
        cout<<'\n';
    }
    return 0;
    }