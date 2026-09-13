#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rounder(string ss,ll n){
    string s="";
    for(int i=0;i<2 and i<ss.size();i++){
        s.push_back(ss[i]);
    }
    ll m=stoll(s);
    ll dibo=0;
    ll ans=0;
    for(ll i=1;i<=m;i++){
        ll d=n*i;
        ll cnt=0;
        string c=to_string(d);
        for(int j=c.size()-1;j>=0;j--){
            if(c[j]=='0')cnt++;
            else break;
        }
        if(cnt>=ans){
            dibo=d;
            ans=cnt;
        }
    }
    return dibo;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m;
        s=to_string(m);
        if(n%2 and n%5){
            for(int i=1;i<s.size();i++)s[i]='0';
            m=stoll(s);
            cout<<n*m<<endl;
        }
        else{
            ll mul=1;
            if(s.size()>2){
                for(int i=0;i<s.size()-2;i++){
                    mul=mul*10;
                }
            }
            cout<<rounder(s,n)*mul<<endl;
        }
    }
    return 0;
    }