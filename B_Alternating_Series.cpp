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
        if(n%2==0){
            for(int i=0;i<n;i++){
                if(i==n-1) cout<<2<<" ";
                else if(i%2==0) cout<<-1<<" ";
                else cout<<3<<" ";
            }cout<<endl;
        }
        else{
            for(int i=0;i<n;i++){
                if(i%2==0) cout<<-1<<" ";
                else cout<<3<<" ";
            }cout<<endl;
        }
    }
    return 0;
    }