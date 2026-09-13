#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,w,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>w>>d;
        ll ww=w;
        ll dd=d;
        ll ans=0;
        cnt=1;
        a=0;
        ll uttor =0;
        while(true){
            if(a%2==0){
                if(cnt<=ww){
                    ww=ww-cnt;
                    ans++;
                }
                else break;
            }
            else {
                if(cnt<=dd){
                    dd=dd-cnt;
                    ans++;
                }
                else break;
            }
            cnt=cnt*2;
            a++;
        }
        a=0;
        cnt=1;
        while(true){
            if(a%2==1){
                if(cnt<=w){
                    w=w-cnt;
                    uttor++;
                }
                else break;
            }
            else {
                if(cnt<=d){
                    d=d-cnt;
                    uttor++;
                }
                else break;
            }
            cnt=cnt*2;
            a++;
        }
        // cout<<uttor<<" "<<ans<<endl;
        cout<<max(ans,uttor)<<endl;
    }
    return 0;
    }