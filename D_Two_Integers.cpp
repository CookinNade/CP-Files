#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>a>>b;
    const ll N=1e18;
    if(a%b==0)cout<<-1<<endl;
    else{
        for(ll i=1;;i++){ 
            if(i*a>N){
                cout<<-1<<endl;
                break;
            }
            else if((i*a)%b==0)continue;
            else{
                cout<<i*a<<endl;
                break;
            }
        }
    }
    
    return 0;
    }