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
        m=n;
        for(int i=1;i<=n;i++){
            if(i==1){
                cout<<2<<" ";
            }
            else if(i==n){
                cout<<1<<endl;
            }
            else {
                cout<<m-i+2<<" ";
            }
        }
    }
    return 0;
    }