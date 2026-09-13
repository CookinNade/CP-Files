#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>m;
        int arr[n+1];
        int a[n+1]={0}; int b[n+1]={0};
        a[0]=0; b[0]=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(arr[i]==0){
                a[i]=a[i-1]+1;
                b[i]=b[i-1];
            }
            else{
                b[i]=b[i-1]+1;
                a[i]=a[i-1];
            }
        }
        int consecb[n+1]={0};
        for(int i=2;i<=n;i++){
            if(arr[i]==arr[i-1]) consecb[i]=consecb[i-1]+1;
            else consecb[i]=consecb[i-1];
        }
        int conseca[n+1]={0};
        for(int i=1;i<=n-1;i++){
            if(arr[i]==arr[i+1]) conseca[i]=consecb[i+1]+1;
            else conseca[i]=conseca[i-1];
        }
        while(m--){
            cin>>l>>r;
            if((a[r]-a[l-1])%3==0 and (b[r]-b[l-1])%3==0){
                int div= r-l+1; int ans =div/3;
                if(consecb[l+1]!= consecb[r] and conseca[l]!=conseca[r-1]){
                    cout<<ans<<endl;
                }
                else cout<<ans+1<<endl;
            }
            else cout<<-1<<endl;
        }

    }
    return 0;
    }