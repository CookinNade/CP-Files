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
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        cin>>k;
        a=arr[k-1];
        k--;
        int rcnt=0,lcnt=0;
        for(int i=k+1;i<n;i++){
            if(arr[i]!=a){
                rcnt++;
                for(;i<n-1;i++){
                    if(arr[i+1]==arr[i])continue;
                    else break;
                }
            }
        }
        for(int i=k-1;i>=0;i--){
            if(arr[i]!=a){
                lcnt++;
                for(;i>=1;i--){
                    if(arr[i-1]==arr[i])continue;
                    else break;
                }
            }
        }
        // cout<<lcnt<<" "<<rcnt<<endl;
        cout<<max(lcnt,rcnt)*2<<endl;
    }
    return 0;
    }