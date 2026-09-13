#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,a,b,c,d,cnt,r,l; 
    string s,t;
    cin>>s>>t;
    bool yes=false;
    n=s.size();
    for(int i=0;i<n;i++){
        int k=0;
        bool ok=true;
        for(int j=i;j<n;j++,k++){
            if(s[j]==t[k])continue;
            else {
                ok=false;
                // cout<<i<<" "<<j<<endl;
            }
        }
        for(int j=0;j<i;j++,k++){
            if(s[j]==t[k])continue;
            else ok=false;
        }
        yes = yes | ok;
    }
    if(yes)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
    }