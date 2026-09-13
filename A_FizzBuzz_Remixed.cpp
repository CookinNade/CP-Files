#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll ans = (n/15)*3;
        if(n%15>=2)ans=ans+3;
        else ans= ans + (n%15)+1;
        cout<<ans<<endl;
    }
    return 0;
    }