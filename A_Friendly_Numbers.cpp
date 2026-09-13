#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        
        d=0;
        int yes=0;
        for(ll i=n;i<=n+1000;i++){
            s = to_string(i); d=0;
            for(int j=0;j<s.length();j++){
                d=s[j]-'0'+d;
            }
            if(n==i-d){
                yes++;
                break;
            }
        }
        if(yes)cout<<10<<endl;
        else cout<<0<<endl;
        // cout<<d<<endl;
    }
    return 0;
    }