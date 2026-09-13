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
        cin>>n>>m>>a>>b;

        if(gcd(n,a)==1 and gcd(b,m)==1 and lcm(m,n)*2>=n*m){

            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
    }