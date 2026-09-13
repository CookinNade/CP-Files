#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        cnt=0;
        ll a[n],b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<n;i++){
            if(i==0){
                ll g=gcd(a[i],a[i+1]);
                if(a[i]/g!=1)cnt++;
            }
            else if(i==n-1){
                ll g=gcd(a[i],a[i-1]);
                if(a[i]/g!=1)cnt++;
            }
            else{
                l=gcd(a[i-1],a[i]);
                c=a[i]/l;
                r=gcd(a[i],a[i+1]);
                d=a[i]/r;
                if(gcd(c,d)!=1)cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
    }