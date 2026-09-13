#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ll t,n,m,l,a,b,c,d,cnt;
    string s;
    cin>>t;
    while(t--){
        set<pair<ll,ll>>st;
        cin>>a>>b>>c;
        ll big = max(a,b);
        ll smol = min(a,b);
        int yesser=0;
        ll diff = (big%smol);
        while(true){
        if(c>big and c>smol)break;
        if(c==smol or c==big){
            yesser++;
        }
        if(c>smol and c<big){
            if((big%smol)==(c%smol)){
                yesser++;
                break;}
        }
        if(c<smol){
            if(diff==0)break;
            else if((smol%diff)==(c%diff)){
                yesser++;
                break;
                
            }
        }
        big=(big%smol);
        if(big==0)break;
        swap(smol,big);
        if(st.find({big,smol})!=st.end())break;
        else st.insert({big,smol});
    }
        if(yesser)cout<<"YES\n";
        else cout<<"NO\n";
    }
}