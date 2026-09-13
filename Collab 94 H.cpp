#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll p=1;
    int f=1;
    // cout<<n<<endl;
    for(ll i=2;i*i<=n;i++){
        // cout<<i<<" "<<n<<endl;
        if(n%i==0){
            ll cnt=0;
            f++;
            // cout<<i<<endl;
            while(n%i==0){
                cnt++;
                n=n/i;
            }
            p=p*(cnt+1);
        }
    }
    // cout<<n<<endl;
    if(n!=1){
        f++;
        p=p*2;
    }
    if(f>2){
        if(p%2==0 and p<=4)cout<<"Y\n";
        else cout<<"N\n";
    }
    else if(f==2 and p%2==0)cout<<"Y\n";
    else cout<<"N\n";
    return 0;
}