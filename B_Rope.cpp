#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long double t,m,a,b,c,d,cnt,r,l,k,x;
    int n;
    cin>>n>>r;
    long double xarr[n]; long double yarr[n];
    for(int i=0;i<n;i++){
        cin>>xarr[i]>>yarr[i];
        // cout<<xarr[i]<<" "<<yarr[i];
    }
    long double len=0;
    for(int i=0;i<n-1;i++){
        long double x1 = xarr[i]; long double x2 =  xarr[i+1];
        long double y1 = yarr[i]; long double y2 = yarr[i+1];
        long double dy = abs(y1-y2);
        long double dx = abs(x1-x2);
        long double lensq = dy*dy + dx*dx;
        len = len + sqrt(lensq);
        // cout<<xarr[2]<<endl;
        if(i==0){
            long double x2 =  xarr[n-1];
            long double y2 =  yarr[n-1];
            long double dy = abs(y1-y2);
            long double dx = abs(x1-x2);
            long double lensq = dy*dy + dx*dx;
            len = len + sqrt(lensq);
        }
    }
    // cout<<len<<endl;
    long double q = n;
    long double zeropoint5=0.5;
    long double pi = 3.1416;
    len = len + 2*pi*r;
    cout<<fixed<<setprecision(2)<<len<<endl;
    return 0;
    }