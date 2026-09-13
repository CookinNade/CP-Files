#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    ll neg=0; ll pos = 0; cnt=0;ll totn=0;ll totp=0;
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=n-1;i>=0;i--){
        if(arr[i]<0){
            swap(pos,neg);
            neg++;
            totp=pos+totp;
            totn=neg+totn;
        }
        else {
            pos++;
            totp=pos+totp;
            totn=neg+totn;
        }
    }
    cout<<totn<<" "<<totp;
    return 0;
    }