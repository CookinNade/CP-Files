#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        cnt=0;
        ll arr[n+1];
        for(int i=1;i<=n;i++)cin>>arr[i];
        b=sqrt(n);
        if(b*b!=n)b++;
        for(ll i=1;i<=n;i++){
            a=arr[i];
            if(a<b){
                for(ll k=1;k<b;k++){
                    if(i>a*k){
                        ll ind = i-a*k;
                        if(i-ind == arr[ind]*a){
                            cnt++;
                        }
                    }
                }
            }
            if(a>=b){
                for(ll k=1;k*a<n;k++){
                    if(i>a*k){
                        ll ind = i-a*k;
                        if(i-ind == arr[ind]*a)cnt++;
                    }
                    ll ind = a*k+i;
                    if(ind <=n and ind-i == a*arr[ind])cnt++;
                    
                }
            }
        }
        cout<<cnt<<endl;

    }
    return 0;
    }