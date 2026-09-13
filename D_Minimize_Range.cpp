#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c,d,cnt,r,l,k,x,n; 
    cin>>n>>k;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>a;
        arr[i]=a%k;
    }
    sort(arr,arr+n);
    vector<ll> v;
    v.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]==v[v.size()-1])continue;
        else v.push_back(arr[i]);
    }
    ll ans=v[v.size()-1]-v[0];
    for(int i=0;i<v.size()-1;i++){
        a=arr[i]+k;
        b=arr[i+1];
        ans=min(ans,a-b);
    }
    cout<<ans<<endl;
    return 0;
    }