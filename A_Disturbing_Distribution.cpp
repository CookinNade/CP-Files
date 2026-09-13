#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        int ans=0;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++){
            if(arr[i]==1)continue;
            else ans=ans+arr[i];
        }
        if(arr[n-1]==1)cout<<ans+1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
    }