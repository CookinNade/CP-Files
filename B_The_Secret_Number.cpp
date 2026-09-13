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
        vector<ll>v;
        for(int i=1;i<=18;i++){
            ll num =1;
            for(int j=1;j<=i;j++){
                num = num*10;
            }
            ll real = n/(num+1);

            if((num+1)*real==n){
                v.push_back(real);
            }
        }
        cout<<v.size()<<endl;
        sort(v.begin(),v.end());
        if(v.size()>0){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }cout<<endl;}
    }
    return 0;
    }