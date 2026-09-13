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
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans=INT_MAX;
        for(int i=1;i<=1000;i++){
            cnt=0;
            for(int j=0;j<n;j++){
                cnt=max(cnt,abs(arr[j]-i));
            }
            ans=min(ans,cnt);
        }
        cout<<ans<<endl;
    }
    return 0;
    }