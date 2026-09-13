#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
const double pi = acos(-1.0);
double radang(long double x){
    return ((ld)x * pi) / 180;
}
const ld ninety = pi/2;
ld w,x,y;
ld cost (ld angle){
    angle = radang(angle); 
    ld tt = tan(angle);
    ld ntt = tan(ninety - angle);
    ld cd = w * (ntt + tt);
    ld h = cd;
    ld b = cd * cd - w * w * tt * tt;
    if(b<0) b = 0;
    b = sqrt(b);
    ld area = x * h * b;
    ld side = y * ((w / sin(angle)) + (w / cos(angle)));
    return area + side;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>w>>x>>y;
        // cout<<sin(ninety)<<endl;
        cout<<fixed<<setprecision(8);
        ld hi = 90 - (ld)0.000000001;
        ld lo = (ld)0.000000001;

        while(hi - lo > 1e-6){
            ld m1 = lo + (hi-lo)/3;
            ld m2 = hi - (hi-lo)/3;
            if(cost(m1) < cost(m2)){
                hi  = m2;
            }
            else {
                lo = m1;
            }
        }
        if(cost(hi) < cost(lo))cout<<cost(hi)<<'\n';
        else cout<<cost(lo)<<'\n';
    }
    return 0;
    }