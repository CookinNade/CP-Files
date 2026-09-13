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
        cin>>a>>b;
        int mn = min(a,b);
        int mx = max(a,b);
        if(a==b)cout<<0<<endl;
        else if(mx%mn==0)cout<<1<<endl;
        else cout<<2<<endl;
    }
    return 0;
    }