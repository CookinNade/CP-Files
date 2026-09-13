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
            if(i<n/2){
                cin>>arr[i];
            }
            else {
                cin>>a;
                a= 2*n-a;
                arr[i]=a;
            }
        }
        ll ans =0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    ans =ans +1ll;
                }
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
    }