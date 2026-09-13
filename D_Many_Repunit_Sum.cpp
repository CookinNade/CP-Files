#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
const ll N=5e5;
ll arr[N+5];
int main () {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    
    ll n,a,b,c,d;
    cin>>n;
    
    fill(arr,arr+N+3,0);
    arr[1]=n;
    for(int i=0;i<n;i++){
        cin>>a;
        arr[a+1]--;
    }
    for(int i=1;i<=N;i++)arr[i]=arr[i]+arr[i-1];
    for(int i=1;i<=N;i++){
        b=arr[i]/10;
        arr[i]=arr[i]%10;
        arr[i+1]=arr[i+1]+b;
    }
    ll ind;
    for(int i=N;i>=0;i--){
        if(arr[i]!=0){
            ind=i;
            break;
        }
    }
    for(int i=ind;i>=1;i--)cout<<arr[i];
    return 0;
    }