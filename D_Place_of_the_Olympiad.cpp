#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,cnt,r,l,m,n,k;
    
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m>>k;
        ll hi=m;
        ll lo =1,mid;
        while(hi-lo>1){
            mid=(hi+lo)/2;
            ll nid=mid+1;
            ll tot = (m%nid) + (m/nid)*mid;
            if(tot*n>=k)hi=mid;
            else lo=mid+1;
            // cout<<hi<<" "<<lo<<" "<<mid<<endl;
        }
        if(((m%(lo+1))+(m/(lo+1)*lo))*n>=k)cout<<lo<<endl;
        else cout<<hi<<endl;

    }   
    return 0;
    }