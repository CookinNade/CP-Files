#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,y,f,sum1,sum2,sum3,sum4; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>x>>y;
        d=lcm(x,y);
        f=n/d;
        a = n/x;
        b = a-f;
        sum1= n*(n+1)/2;
        sum2=(n-b)*(n-b+1)/2;
        // sum4=b*(b+1)/2;
        c=n/y;
        ll e = n/y;
        ll g = e-f;
        sum3=g*(g+1)/2;
        cout<<sum1-sum2-sum3<<endl;
        // cout<<sum1-sum2<<endl;
        // cout<<sum3<<endl;

    }
    return 0;
    }