#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,cnt,k; 
    cin>>t;
    while (t--){
        int a[60] = {};
        int b[60] = {};        
        int ans[60] = {};
        int m = -1;
        for(int i=0;i<60;i++){
            n = (1ll<<i);
            cout<<"? "<<n<<" "<<n<<endl;
            cin>>ans[i];
        }
        for(int i=0;i<60;i++){
            if(ans[i]){
                m = i;
                a[i] = 1;
                break;
            }
        }
        // cout<<"this is my m "<<m<<endl;
        for(int i=0;i<60;i++){
            if(i==m)continue;
            n = (1ll<<m);
            n = n + (1ll<<i);
            int r;
            if(ans[i]){
                cout<<"? "<<n<<" "<<n<<endl;
                cin>>r;
                if(r) a[i] = 1;
                else b[i] = 1;
            }
            else{
                cout<<"? "<<n<<" "<<n<<endl;
                cin>>r;
                if(r){
                    a[i] = 1;
                    b[i] = 1;
                }
            }
        }
        ll na = 0;
        ll nb = 0;
        for(int i=0;i<60;i++){
            if(a[i]) na = na + (1ll<<i);
            if(b[i]) nb = nb + (1ll<<i);
        }
        cout<<"! "<<min(na,nb)<<" "<<max(na,nb)<<endl;
    }
    return 0;
    }