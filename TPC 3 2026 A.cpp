#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    ll nk = k;
    int cnt = 0;
    while(true){
        cnt++;
        ll nb=0,nc=0;
        if(nk>a){
            nk -= a;
            nb += a;
            a = 0;
        }
        else{
            nb += nk;
            a -= nk;
            nk = 0;
        }
        if(nk>b){
            nk -= b;
            nc += b;
            b = 0;
        }
        else{
            nc += nk;
            b -= nk;
            nk = 0;
        }
        if(nk>0){
            break;
        }
        nk = k;
        b += nb;
        c += nc;
    }
    cout<<cnt;
    return 0;
    }