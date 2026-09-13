#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x,y; 
    cin>>t;
    string s;
    while (t--){
        cin>>a>>x>>y;
        if((a>x and a>y) or (a<x and a<y)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }