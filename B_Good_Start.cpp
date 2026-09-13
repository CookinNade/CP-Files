#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,w,h; 
    cin>>t;
    string s;
    while (t--){
        cin>>a>>b>>w>>h;
        ll x1,x2,y1,y2;
        int yes=0;
        cin>>x1>>y1>>x2>>y2;
        if(abs(x1-x2)%w==0 and x1!=x2)yes++;
        if(abs(y1-y2)%h==0 and y1!=y2)yes++;
        
        
        if(yes)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
    }
    