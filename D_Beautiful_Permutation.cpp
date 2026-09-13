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
        cin>>n;
        ll one; ll two;
        cout<<1<<" "<<1<<" "<<n<<endl;
        cout.flush();
        cin>>one;
        cout<<2<<" "<<1<<" "<<n<<endl;
        cout.flush();
        cin>>two;
        l=1; r=n;
        ll diff=two-one;
        r=n; l=1; ll mid;
            while(r-l>1){
                mid=(l+r)/2;
                cout<<1<<" "<<mid<<" "<<n<<endl;
                cout.flush();
                cin>>one;
                cout<<2<<" "<<mid<<" "<<n<<endl;
                cout.flush();
                cin>>two;
                if(two-one==diff){
                    l=mid;
                }
                else{
                    r=mid;
                }
            }
            cout<<1<<" "<<r<<" "<<n<<endl;
            cout.flush();
            cin>>one;
            cout<<2<<" "<<r<<" "<<n<<endl;
            cout.flush();
            cin>>two;
            if(two-one==diff)cout<<'!'<<" "<<r<<" "<<r+diff-1<<endl;
            else cout<<'!'<<" "<<l<<" "<<l+diff-1<<endl;
            cout.flush();
            
        
    }
    return 0;
    }