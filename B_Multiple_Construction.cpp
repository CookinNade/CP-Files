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
        for(int i=n;i>=1;i--){
            cout<<i<<" ";
            if(i==1){
                cout<<n<<" ";
                for(int j=1;j<=n-1;j++){
                    cout<<j<<" ";
                }
            }
        }cout<<endl;
    }
    return 0;
    }