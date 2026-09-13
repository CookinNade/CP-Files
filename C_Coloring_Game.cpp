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
        for(ll i=0;i<n;i++)cin>>arr[i];
        ll bog = arr[n-1];
        ll cnt=0;
        for(ll i=n-1;i>=2;i--){
            for(ll j=i-1;j>=1;j--){
                ll hi = j-1;
                ll lo =0;
                while(hi-lo>1){
                    ll mid=(hi+lo)/2;
                    if(arr[mid]+arr[j]>arr[i] and arr[i]+arr[j]+arr[mid]>bog){
                        hi=mid;
                    }
                    else lo=mid;
                }
                if(arr[lo]+arr[j]>arr[i] and arr[i]+arr[j]+arr[lo]>bog){
                    cnt=cnt+j;
                }
                else if(arr[hi]+arr[j]<=arr[i] or arr[i]+arr[j]+arr[hi]<=bog)continue;
                else cnt=cnt+j-hi;
                
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
    }