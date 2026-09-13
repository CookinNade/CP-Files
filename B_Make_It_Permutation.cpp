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
        cout<<2*n-1<<endl;
        cout<<1<<" "<<1<<" "<<n<<endl;
        for(int i=2;i<=n;i++){
            cout<<i<<" "<<1<<" "<<i-1<<endl;
            cout<<i<<" "<<i<<" "<<n<<endl;
        }
    }
    return 0;
    }