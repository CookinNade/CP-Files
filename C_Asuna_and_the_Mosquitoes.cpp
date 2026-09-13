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
        ll even =0; ll odd=0; ll maxeven=0; ll maxodd=0; ll sumeven=0; ll sumodd=0;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a%2==0){
                even++;
                maxeven = max(a,maxeven);
                sumeven=sumeven+a;
            }
            else {
                odd++;
                maxodd = max(a,maxodd);
                sumodd=sumodd+a;
            }
        }

        if(odd==0 or even==0){
            cout<<max(maxeven,maxodd)<<endl;
        }
        else cout<<sumodd+sumeven-odd+1<<endl;

    }
    return 0;
    }