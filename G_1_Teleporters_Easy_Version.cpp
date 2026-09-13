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
        cin>>n>>c;
        ll arr[n+1];
        for(int i=1;i<=n;i++){
            cin>>a;
            arr[i]=a+i;
        }
        sort(arr+1,arr+n+1);
        cnt=0;
        int ans=0;
        // for(int i=1;i<=n;i++){
        //     cout<<arr[i]<<" ";
        // }
        for(int i=1;i<=n;i++){
            cnt=cnt+arr[i];
            if(cnt>c){
                ans=i-1;
                break;
            }
            else if(i==n and cnt<=c){
                ans=n;
            }
            else continue;
        }
        cout<<ans<<endl;
    }
    return 0;
    }