#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,s,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    
    while (t--){
        cin>>s>>k>>m;
        if(k>=s){
            if((m%k)>=s)cout<<0<<endl;
            else cout<<s-(m%k)<<endl;
        }
        else{
            a=m/k;
            // cout<<a<<endl;
            if(a%2==0)cout<<s-(m%k)<<endl;
            else cout<<k-(m%k)<<endl;
        }
    }
    return 0;
    }