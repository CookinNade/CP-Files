#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n , b;
    cin>>n>>b;
    ll arr[n-1];
    for(int i=0;i<n-1;i++)cin>>arr[i];
    sort(arr,arr+n-1,greater<int>());
    if(arr[0]>=0){
        for(int i=0;i<n-1;i++) if(arr[i]>=0)b += arr[i];
        cout<<b<<endl;
    }
    else{
        if(b - abs(arr[0]) >= 0)cout<<b - abs(arr[0])<<endl;
        else cout<<-1<<endl;
    }
    return 0;
    }