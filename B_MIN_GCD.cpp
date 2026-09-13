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
        ll arr[n];
        vector<ll>v;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll lil=arr[0];
        l=0;
        for(int i=1;i<n;i++){
            if(arr[i]==lil){
                l=2;
                break;
            }
            else if(arr[i]%lil==0){
                v.push_back(arr[i]);
            }
        }
        ll gd;
        if(v.size()>=2){
            for(int i=1;i<v.size();i++){
                if(i==1){
                    gd=gcd(v[0],v[i]);
                }
                else gd=gcd(gd,v[i]);
                if(gd==lil){
                    l=2;
                    break;
                }
            }
        }
        if(l>=2){
            cout<<"Yes\n";
        }
        else cout<<"No\n";

    }
    return 0;
    }