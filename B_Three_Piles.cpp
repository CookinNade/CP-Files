#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a>=b){
            cout<<a+c-b<<'\n';
        }
        else{
            ll can1 = b-a;
            ll aa = a + c;
            ll can2 = abs(b-aa);
            cout<<max(can1,can2)<<'\n';
        }
    }
    return 0;
    }