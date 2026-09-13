#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,b,c,n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    ll eng=0;
    ll ans=arr[0];
    for(int i=0;i<n-1;i++){
        if(arr[i]+eng>=arr[i+1])
            eng=eng+arr[i]-arr[i+1];
            
        else {
            ans = ans+arr[i+1]-arr[i]-eng;
            eng=0;
        }
    }
    cout<<ans<<endl;
}