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
        int arr[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        cnt=0;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                // cout<<i<<" "<<n-1-i<<" "<<endl;
                if(arr[i][j]==arr[n-1-i][n-1-j])continue;
                else cnt++;
            }
        }
        int lcnt=0,i;
        if(n%2==1){
            i=n/2;
            for(int j=0;j<n;j++){
                // cout<<arr[i][j]<<" "<<arr[i][n-j-1]<<" ";
                if(arr[i][j]==arr[i][n-j-1])continue;
                else lcnt++;
            }
        }
        cnt=cnt+lcnt/2;
        // cout<<cnt<<endl;
        if(n==1)cout<<"YES\n";
        else if(cnt>k)cout<<"NO\n";
        else if(cnt<=k){
            if((k-cnt)%2==0 and n%2==0)cout<<"YES\n";
            else if(n%2==1)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
    }