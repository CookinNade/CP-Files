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
        cin>>a>>b;
        if(a==1){
            cout<<b*b<<endl;
        }
        else if(a%2==0 or b%2==0){
                cout<<b*2<<endl;
            }
        else if (lcm(a,b)==b){
                int x= b/a;
                cout<<x*b<<endl;
            }    
        else cout<<lcm(a,b)<<endl;
        
    }
    return 0;
    }