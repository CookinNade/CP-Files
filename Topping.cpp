#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,p;
    cin>>n>>p;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(i+j+k+3 <= p){
                    ans = max(ans, arr[i] + arr[j] + arr[k]);
                    // cout<<arr[i] + arr[j] + arr[k]<<" "<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
    }