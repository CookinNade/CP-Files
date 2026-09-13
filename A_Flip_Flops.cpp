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
        cin>>n>>c>>k;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n);
        ll ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=c){
                d=c-arr[i];
                if(d>=k){
                    arr[i]=arr[i]+k;
                    k=0;
                }
                else{
                    arr[i]=arr[i]+d;
                    k=k-d;
                }
                c=c+arr[i];
            }
        }
        cout<<c<<endl;
    }
    return 0;
    }