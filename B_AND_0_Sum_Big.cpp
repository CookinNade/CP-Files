#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        ll M = 1e9;
        M=M+7;
        cin>>n>>k;
        ll ans =1;
        for(int i=0;i<k;i++){
            ans=(ans*n)%M;
        }
        cout<<ans<<endl;

    }
    return 0;
    }