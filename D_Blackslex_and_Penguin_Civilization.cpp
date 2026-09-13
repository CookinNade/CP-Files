#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;


 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll arr[70000];
        fill(arr,arr+70000,0ll);
        ll a = 1ll<<n;
        a--;
        ll mx=a+1;
        vector<ll>v;
        v.push_back(a);
        arr[a]=1;
        for(;;){
            n--;
            a=(1ll<<(n))-1;
            if(a==1 or a==0){
                break;
            }
            v.push_back(a); arr[a]=1;
            b=(a+1)*2;
            ll p=b;
            b=b+a;
            for(;b<mx;b=b+p){
                if(arr[b]==0){
                    arr[b]=1;
                    v.push_back(b);
                }
            }
        }
        for(int i=1;i<mx;i=i+2){
            if(arr[i]==0)v.push_back(i);
        }
        for(int i=0;i<mx;i=i+2){
            if(arr[i]==0)v.push_back(i);
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
    }