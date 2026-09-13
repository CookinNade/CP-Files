#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,y; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>x>>y>>s;
        ll cnt8=0,cnt4=0;
        for(int i=0;i<n;i++){
            if(s[i]=='8')cnt8++;
            else cnt4++;
        }
        x=abs(x); y=abs(y);
        x=x-cnt8; y=y-cnt8;
        cnt=0;
        if(x>=0)cnt=cnt+x;
        if(y>=0)cnt=cnt+y;
        if(cnt4>=cnt)cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
    }