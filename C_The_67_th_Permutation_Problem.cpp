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
        cin>>n;
        cnt=1;
        m=n*3;
        for(int i=0;i<n;i++){
            cout<<cnt<<" ";
            cout<<m<<" "; m--;
            cout<<m<<" "; m--;
            cnt++;
        }
        cout<<endl;
    }
    return 0;
    }