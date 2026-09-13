#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n; 
    cin>>n;
    for(int x=1;x<=n;x++){
        __int128 i =x;
        __int128 total = ((i*i*i*i-i*i)/2);
        total = total - (i-1)*(i-2)*4ll;
        cout<<(ll)total<<endl;
    }
    return 0;
    }