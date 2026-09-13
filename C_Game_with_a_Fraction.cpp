#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,p,q; 
    cin>>t;
    string s;
    while (t--){
        cin>>p>>q;
        if(p>=q)cout<<"Alice\n";
        else{
            d=q-p;
            if(2*d<=p)cout<<"Bob\n";
            else cout<<"Alice\n";
        }
    }
    return 0;
    }