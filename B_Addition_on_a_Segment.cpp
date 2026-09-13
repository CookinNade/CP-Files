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
    ll s;
    while (t--){
        cin>>n;
        s=0; cnt=0;
        for(int i=0;i<n;i++){
            cin>>a;
            s=s+a;
            if(a!=0)cnt++;
        }
        if(s>=2*n-1)cout<<cnt<<endl;
        else{
            cout<<min(cnt,s-n+1)<<endl;
        }
    }
    return 0;
    }