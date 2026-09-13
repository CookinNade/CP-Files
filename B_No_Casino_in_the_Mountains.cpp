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
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans=0;cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0 and cnt<k){
                cnt++;
                if(cnt==k){
                    i++;
                    ans++;
                    cnt=0;
                }
            }
            else if(arr[i]==1){
                cnt=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
    }