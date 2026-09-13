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
        cin>>n>>x>>k>>s;
        cnt=0; ll ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L')x--;
            else x++;
            cnt++;
            if(x==0){
                ans++;
                break;  
            }
        }
        // cout<<cnt<<endl;
        k=k-cnt;
        cnt=0;
        int yes=0;
        if(ans==0) {
            cout<<ans<<endl;
            continue;
        }
        x=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L')x--;
            else x++;
            cnt++;
            if(x==0){
                yes++;
                break;
            }
        }
        if(yes)cout<<(k/cnt) + ans<<endl;
        else cout<<ans<<endl;
        
    }
    return 0;
    }