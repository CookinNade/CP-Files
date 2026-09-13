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
        cin>>n>>x;
        int l=n;int m=0;
        for(int i=1;i<=n;i++){
            cin>>a;
            if(a==1){
                l=min(i,l);
                m=max(i,m);
            }
        }
        if(m-l+1<=x){
            cout<<"YES\n";
        }
        else cout<<"NO\n";

    }
    return 0;
    }