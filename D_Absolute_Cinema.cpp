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
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll sum=0;
        m=(arr[0]+arr[n-1])/(n-1);
        ll ans[n];
        for(int i=1;i<n;i++){
            d=arr[i-1]-arr[i];
            ll res=m-d;
            res=res/2;
            res=res-sum;
            cout<<res<<" ";
            sum=sum+res;
        }
        cout<<m-sum<<" ";
        cout<<endl;
    }
    return 0;
    }