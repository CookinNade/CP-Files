#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll ans =0;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a==0)ans++;
            else ans=ans+a;
        }
        cout<<ans<<endl;
    }
    return 0;
    }