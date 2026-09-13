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
    int j=1;
    while (j<=t){
        cin>>n>>a>>b;
        cout<<"Case #"<<j<<": ";
        for(int i=0;i<2*n;i++){
            if(i==2*n-1){
                cout<<b<<endl;
            }
            else cout<<1<<" ";
        }

        j++;
    }
    return 0;
    }