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
        cin>>n>>x;
        ll bit;
        for(int i=0;i<=31;i++){
            if((x>>i)&1) continue;
            else {
                bit=i;
                break;
            }
        }
        ll ans=0;
        ll ind = (1ll<<bit);
        vector<ll>v;
        for(int i=0;i<ind and i<n;i++){
            v.push_back(i);
            ans=i|ans;
        }
        if(ans!=x){
            if(v.size()<n)v.push_back(x);
            else{
                v.pop_back();
                v.push_back(x);
            }
        }
        if(v.size()!=n){
            for(int i=v.size();i<n;i++){
                v.push_back(x);
            }
        }
        for(auto x:v){
            cout<<x<<" ";
        }cout<<endl;
        

    }
    return 0;
    }