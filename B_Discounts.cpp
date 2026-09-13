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
        cin>>n>>k;
        ll arr[n]; 
        ll disc[k];
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<k;i++)cin>>disc[i];
        sort(arr,arr+n); sort(disc,disc+k);
        r=n-1;
        ll cnt=0;
        for(int i=0;i<k;i++){
            int am=disc[i];
            if(am<=r+1 and r>=0){
                for(int j=0;j<am-1;j++,r--){
                    cnt=cnt+arr[r];
                    // cout<<arr[r]<<" "<<disc[i]<<" \n";
                }
                // cout<<endl;
                r--;
            }
            else {
                for(;r>=0;r--) cnt=cnt+arr[r];
                break;
            }
        }
        for(;r>=0;r--)cnt=cnt+arr[r];
        cout<<cnt<<endl;
    }
    return 0;
    }