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
        cin>>n>>a;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        b=a+1; ll cnta=0,cntb=0;
        r=a-1;
        for(int i=0;i<n;i++){
            if(abs(b-arr[i])<abs(a-arr[i])) cnta++;
            if(abs(r-arr[i])<abs(a-arr[i])) cntb++;
        }
        if(cnta>cntb)cout<<b<<endl;
        else cout<<r<<endl;
    }
    return 0;
    }