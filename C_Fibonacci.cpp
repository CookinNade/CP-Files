#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define double ll

ll m[2][2]; 
ll ans[2][2];
const ll M = 1e9+7;
void power(){
    ll new_m [2][2];
    for(int i=0;i<2;i++)for(int j=0;j<2;j++) new_m[i][j] = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                new_m[i][k] = (new_m[i][k] + (m[i][j] * m[j][k]) % M) % M;
            }
        }
    }
    for(int i=0;i<2;i++)for(int j=0;j<2;j++) m[i][j] = new_m[i][j];
    return;
}
ll mexpo(ll n){
    ll h = 1;
    ll s = 0;
    // for(int i=0;i<2;i++)for(int j=0;j<2;j++) cout<<m[i][j]<<" ";
    while(n>0){
        if(n%2){
            // cout<<h<<" "<<s<<endl;
            ll new_h = (h * m[0][0] + s * m[1][0]) % M;
            ll new_s = (s * m[1][1] + h * m[0][1]) % M;
            h = new_h;
            s = new_s;
            // cout<<h<<" "<<s<<endl;
        }
        power();
        n >>= 1;
    }
    return s;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    m[0][0] = 0; m[1][1] = 1;
    m[1][0] = 1; m[0][1] = 1;
    cout<<mexpo(n);
    
    return 0;
    }