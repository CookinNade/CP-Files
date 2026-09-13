#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,y; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>y>>r;
        ll tot = r+y/2;
        if(tot>n)cout<<n<<endl;
        else cout<<tot<<endl;
    }
    return 0;
    }