#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,q; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        ll xr[n+1]; xr[0]=0;
        cin>>s;
        a=0;b=0;c=0;
        for(int i=0;i<n;i++){
            c=c^arr[i];
            xr[i+1]=c;
            if(s[i]=='0')b=b^arr[i];
            else a=a^arr[i];
        }
        cin>>q;
        while(q--){
            cin>>c;
            if(c==2){
                cin>>d;
                if(d==1)cout<<a<<" ";
                else cout<<b<<" ";
            }
            else{
                cin>>l>>r;
                a=a ^ xr[r] ^ xr[l-1];
                b=b ^ xr[r] ^ xr[l-1];
            }
        }
        cout<<endl;
    }
    return 0;
    }