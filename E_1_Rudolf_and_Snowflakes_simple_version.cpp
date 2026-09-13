#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    
    string s;
    set<ll>st;
    const ll N= 1e6;
    for(ll i=2;i*i+i+1<=N;i++){
        ll add=i+1;
        ll temp=i;
        ll num=add;
        for(;;){
            
            temp = temp*i;
            num=temp+num;
            // if(i==2)cout<<num<<endl;
            if(num<=N){
                st.insert(num);
            }
            else break;
        }
    }
    cin>>t;
    while (t--){
        cin>>n; int yes=0;
        if(st.find(n)!=st.end())cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }