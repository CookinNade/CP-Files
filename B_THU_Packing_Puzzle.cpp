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
        cin>>a>>b>>c;
        ll ans=0;
        ll q;
        n=a,m=b,q=c;
        if(a and c){
            d=min(a,c);
            ans=d*4+ans;
            a=a-d;
            c=c-d;
        }
        if(a/2 and b){
            d=min(a/2,b);
            ans=d*7+ans;
            a=a-d*2;
            b=b-d;
        }
        if(a and b){
            d=min(a,b);
            ans=d*5+ans;
            a=a-d;
            b=b-d;
        }
        if(a){
            ans=ans + 3;
            a--;
            ans=a*2+ans;
            a=0;
        }
        if(b){
            ans=ans + b*3;
            b=0;
        }
        if(c){
            ans=ans + c*3;
            c=0;
        }

        ll tot=ans;
        ans=0;
        a=n,b=m,c=q;    
        if(a/2 and b){
            d=min(a/2,b);
            ans=d*7+ans;
            a=a-d*2;
            b=b-d;
        }

        if(a and c){
            d=min(a,c);
            ans=d*4+ans;
            a=a-d;
            c=c-d;
        }
        if(a and b){
            d=min(a,b);
            ans=d*5+ans;
            a=a-d;
            b=b-d;
        }
        if(a){
            ans=ans + 3;
            a--;
            ans=a*2+ans;
            a=0;
        }
        if(b){
            ans=ans + b*3;
            b=0;
        }
        if(c){
            ans=ans + c*3;
            c=0;
        }
        cout<<min(tot,ans)<<endl;
    }
    return 0;
    }