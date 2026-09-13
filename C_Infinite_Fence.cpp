#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll r,b,k,del,th;
        cin>>r>>b>>k;
        ll big=max(r,b);
        ll smol=min(r,b);
        ll chk=big/smol;
        if(big%smol!=0)chk++;
        if(k>chk)cout<<"OBEY\n";
        else if(k<chk)cout<<"REBEL\n";
        else {
            del=big%smol;
            if(del==0)cout<<"OBEY\n";
            else{
                // cout<<"ekhane dhukse";
                th=big/del;
                if(big%del!=0)th++;
                // cout<<th<<" ";
                if((th*smol)%big==0)cout<<"OBEY\n";
                else cout<<"REBEL\n";
            }
        }
    }
    
    return 0;
}