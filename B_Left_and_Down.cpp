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
        cin>>a>>b>>k;
        if(k>=max(a,b))cout<<1<<endl;
        else if (a==b)cout<<1<<endl;
        else if(a!=b){
            ll gd = gcd(a,b);
            if((a/gd)<=k and (b/gd)<=k)cout<<1<<endl;
            else cout<<2<<endl;
        }
        else cout<<2<<endl;
    }
    return 0;
    }