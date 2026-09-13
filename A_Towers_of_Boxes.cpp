#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x,w; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>w>>d;
        if(w>d)cout<<n<<endl;
        else{
            cnt=d/w;
            cnt++;
            ll ans = n/cnt;
            if(n%cnt)ans++;
            cout<<ans<<endl;
        }
    }
    return 0;
    }