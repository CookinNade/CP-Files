#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,s; 
    cin>>t;
    while (t--){
        cin>>n>>k>>b>>s;
        ll lo = b*k;
        ll hi = (k-1)*n+b*k;
        if(s<=hi and s>=lo){
            for(int i=0;i<n;i++){
                if(i==0){
                    if((b*k+k-1)>s){
                        cout<<s<<" ";
                        s=0;
                    }
                    else {
                        cout<<b*k+k-1<<" ";
                        s=s-(b*k+k-1);
                    }
                }
                else {
                    if(s>=k-1){
                        cout<<k-1<<" ";
                        s=s-(k-1);
                        // cout<<s<<"  The s is   ";
                    }
                    else {
                        cout<<s<<" ";
                        s=0;
                    }
                }
            }
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
    }