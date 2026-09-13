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
        for(int i=0;i<=20;i++){
            if(((n>>i)&1)==1){
                cnt=i;
                break;
            }
        }
        // if(n%2){
            ll sum = (n*(n+1))/2;
            ll arr[n];
            // cout<<sum<<endl;
            arr[n-1]=1;
            for(int i=2;i<=n-1;i++){
                arr[i-1]=i ^ 1;
                sum=sum-arr[i-1];
            }
            arr[0]=sum-1;
            for(int i=0;i<n;i++)cout<<arr[i]<<" ";
            cout<<endl;
        // }
        // else{
        //     ll sum = (n*(n+1))/2;
        //     ll arr[n];
        //     // cout<<sum<<endl;
        //     arr[n-1]=2;
        //     for(int i=2;i<=n-1;i++){
        //         arr[i-1]=i ^ 2;
        //         sum=sum-arr[i-1];
        //     }
        //     arr[0]=sum-2;
        //     for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        //     cout<<endl;
        // }
    }

    return 0;
    }