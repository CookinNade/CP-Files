#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void primefactors(ll n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n!=1)cout<<n<<endl;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n;
    cin>>n; 
    primefactors(n);
    return 0;
    }