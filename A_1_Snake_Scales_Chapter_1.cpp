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
    int j=1;
    while (j<=t){
        cin>>n;
        int arr[n];
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<n;i++){
            ans=max(ans,abs(arr[i]-arr[i-1]));
        }
        cout<<"Case #"<<j<<": "<<ans<<endl;
        j++;
    }
    return 0;
    }