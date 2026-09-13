#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x;
    string s;
    cin>>n>>s;
    a=0;b=0;
    for(int i=0;i<n;i++){
        if(s[i]=='+')a++;
        else b++;
    }
    ll big=max(a,b);
    ll smol=min(a,b);
    
    cin>>t;
    // cout<<t<<" "<<big<<" "<<smol<<endl;
    while (t--){
        // cout<<"dhukse \n";
        ll diff=big-smol;
        cin>>a>>b;
        ll mx = max(a,b);
        ll mn = min(a,b);
        ll g=lcm(a,b);
        a=g/mn;
        b=g/mx;
        d=a-b;
        if(a==b){
            if(diff==0)cout<<"YES\n";
            else cout<<"NO\n";
            continue;
        }
        if(diff%d)cout<<"NO\n";
        else{
            c=diff/d;
            ll taken = min(big/a,smol/b);
            if(taken>=c)cout<<"YES\n";
            else cout<<"NO\n";
            // cout<<c<<" "<<a<<" "<<b<<" "<<g<<" "<<taken<<endl;
        }

    }
    return 0;
    }