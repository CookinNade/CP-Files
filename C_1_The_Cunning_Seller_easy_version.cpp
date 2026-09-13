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
        cin>>n;
        ll cost =0;
        for(;n>0;){
            ll sum=1; cnt=0;
            while (sum * 3 <= n) {
                sum =sum*3;
                cnt++;
            }
            // cost = cost + (sum*3) + (cnt*sum/3);
            cost = cost + (sum*3) + (cnt*sum/3);
            n=n-sum;
            
            // // cout<<cnt<<endl;
            // cout<<(sum*3) + (cnt*sum/3)<<endl;
            // cout<<n<<endl;
        }
        cout<<cost<<endl;
    }
    return 0;
    }