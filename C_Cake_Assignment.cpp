#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>k>>x;
        vector<int>ve;
        ll tot = (1ll<<(k+1));
        ll c = x;
        ll v = tot-x;
        while(c!=tot/2){
            if(c*2<=tot){
                v=v-c;
                c=c*2;
                ve.push_back(1);
            }
            else{
                c=c-v;
                v=v*2;
                ve.push_back(2);
            }
            // cout<<c<<" "<<v<<endl;
        }
        cout<<ve.size()<<endl;
        for(int i=ve.size()-1;i>=0;i--){
            cout<<ve[i]<<" ";
        }cout<<endl;
    }
    return 0;
    }