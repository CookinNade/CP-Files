#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,del; 
    cin>>t;
    string s;
    while (t--){
        cin>>n; map<ll,ll>mp;
        for(int i=0;i<n;i++){
            cin>>a;
            mp[a]++;
        }
        auto it=mp.begin();int noer=0;
        for(;;++it){
            auto nit=it;
            nit++;
            if(nit==mp.end()){
                if((*it).second%2==1) noer++;
                break;
            }
            else if((*it).second%2==0){
                del=(*nit).first-(*it).first;
                if((*it).second>=2*del+2){
                    mp[(*nit).first]=(*nit).second+(*it).second-2*del;
                }
                else continue;
            }
            else if((*it).second%2==1){
                del=(*nit).first-(*it).first;
                if((*it).second>=2*del+1){
                    mp[(*nit).first]=(*nit).second+(*it).second-2*del;
                    mp[(*it).first]=2;
                }
                else {
                    noer++;
                    break;
                }
            }
        }
        cout<<(noer>0? "No\n":"Yes\n" );
    }
    return 0;
    }