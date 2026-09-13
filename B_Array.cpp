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
        for(int i=0;i<n;i++)cin>>arr[i];
        ll ans[n];
        fill(ans,ans+n,0);
        for(int i=0;i<n-1;i++){
            l=0,r=0; a=arr[i];
            for(int j=i+1;j<n;j++){
                if(a>arr[j])r++;
                else if(arr[j]>a)l++;
            }
            ans[i]=max(r,l);
        }
        for(auto y:ans)cout<<y<<" ";
        cout<<endl;
    }
    return 0;
    }