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
        cin>>a>>b;

        ll barr[32]; ll arr[32];
        for(ll i=0;i<31;i++){
            if(((1ll<<i)&a)) arr[i]=1;
            else arr[i]=0;
            if(((1ll<<i)&b)) barr[i]=1;
            else barr[i]=0;
        }
        int laga=0; int lagb=0;
        for(int i=0;i<31;i++){
            if(arr[i]==1)laga=i+1;
            if(barr[i]==1)lagb=i+1;
        }
        if(lagb>laga){
            cout<<-1<<endl;
        }
        else{
            vector<ll>v;
            vector<ll>vv;
            for(ll i=0;i<31;i++){
                if(arr[i]==barr[i])continue;
                else{
                    if(arr[i]==0)v.push_back((1ll<<i));
                    else vv.push_back((1ll<<i));
                }
            }
            cout<<v.size()+vv.size()<<endl;
            for(ll i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            for(ll i=0;i<vv.size();i++){
                cout<<vv[i]<<" ";
            }cout<<endl;

        }
        // for(int i=0;i<4;i++){
        //     cout<<arr[i]<<" ";
        // }cout<<endl;
        // for(int i=0;i<4;i++){
        //     cout<<barr[i]<<" ";
        // }cout<<endl;
    }
    return 0;
    }