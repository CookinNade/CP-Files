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
        cin>>n>>m;
        if(m>(n*(n+1))/2 or m<n){
            cout<<-1<<endl;
            continue;
        }
        ll ans=n;
        bool use[n+1];
        fill(use+1,use+n+1,false);
        r=1;
        use[1]=true;
        for(ll i=n;i>=2;i--){
            if(ans+i-1<=m){
                use[i]=true;
                ans=ans+i-1;
                r=max(r,i);
            }
        }
        cout<<r<<endl;
        if(r!=1)cout<<1<<" "<<r<<endl;
        for(int i=2;i<=n;i++){
            if(i==r)continue;
            else if(use[i])cout<<r<<" "<<i<<endl;
            else cout<<1<<" "<<i<<endl;
        }
    }
    return 0;
    }