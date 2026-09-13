#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,normal,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;        
        int arr[n]; int arrb[n];
        for(int i=0;i<n;i++) cin>>arr[i]; for(int i=0;i<n;i++) cin>>arrb[i];
        int noer=0; 
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                if(arr[i]==arrb[i]){
                    x=-1;continue;
                }
                else {
                    noer++;break;
                }
            }
            // cout<<x<<endl;
            if(arr[i]==arrb[i]){
                x=-1;
                //  cout<<" equal\n";
            }
            else if(x!=-1 and (arr[i]^x)==arrb[i]){
                x=(arr[i]^x);
                //  cout<<" from 1 \n";
            }
            else if((arr[i]^arr[i+1])==arrb[i]){
                x=(arr[i]^arr[i+1]);
                //  cout<<" from 2 \n";
                // cout<<(arr[i]^arr[i+1])<<" "<<arrb[i]<<endl;
            }
            else {
                    noer++;break;
                }
        }
        if(noer)cout<<"NO\n";
        else cout<<"YES\n";
        
    }
    return 0;
    }