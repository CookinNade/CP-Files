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
            cin>>b;
            arr[i]=b;
        }
        sort(arr+1,arr+n+1);
        int ans=0; cnt=0;
        // for(int i=1;i<=n;i++){
        //     cout<<arr[i]<<" ";
        // }cout<<endl;
        int j=-1;
        for(int i=1;i<=n;i++){
            if(arr[i]<=c){
                j=i;
            }
        }
        // cout<<j<<"here "<<endl;
        for(int i=j;i>=1;i--){
            if(arr[i]<=c){
                ans++;
                // cout<<"dhukse when i was "<<i<<endl; 
                for(int i=1;i<=n;i++){
                arr[i]=arr[i]*2;
                // cout<<arr[i]<<" ";
            }
            // cout<<endl;
            }
            
        }
        if(j==-1){
            cout<<n<<endl;
        }
        else cout<<n-ans<<endl;
    }
    return 0;
    }