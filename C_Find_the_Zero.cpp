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
        ll ans=0;
        for(int i=2;i<=n;i++){
            cout<<"? "<<2*i - 1<<" "<<2*i<<endl;
            cin>>a;
            if(a){
                ans=2*i;
                break;
            }
        }
        if(ans){
            cout<<"! "<<ans<<endl;
            continue;
        }
        cout<<"? "<<1<<" "<<3<<endl;
        cin>>a;
        if(a){
            cout<<"! "<<1<<endl;
            continue;
        }
        cout<<"? "<<1<<" "<<4<<endl;
        cin>>a;
        if(a){
            cout<<"! "<<1<<endl;
        }
        else cout<<"! "<<2<<endl;
    }
    return 0;
    }