#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ll a,b,c;
    cin>>a>>b>>c;
    swap(b,c);
    ll ans=a*2;
    if(c and b>=2){
        ans=ans+2;
        b=b-2;
        ans=ans+3;
        c--;
        ans=ans+c*2;
    }
    if(b){
        b=b/2;
        ans=ans+b*3;
    }
    cout<<ans<<endl;
    return 0;
}