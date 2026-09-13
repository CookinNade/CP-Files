#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    
    string s;
    // while (t--){
    cin>>n;
    if(n<=3 and n!=1){
        cout<<"NO SOLUTION\n";
    }
    else if(n==1)cout<<1<<endl;
    else {
        for(int i=2;i<=n;i=i+2){
            cout<<i<<" ";
        }
        for(int i=1;i<=n;i=i+2){
            cout<<i<<" ";
        }
        
        cout<<endl;
    }
    // }
    return 0;
    }