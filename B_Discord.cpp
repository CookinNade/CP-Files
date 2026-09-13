#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    // cin>>t;
    string s;
    // while (t--){
    // }
    cin>>n>>m;
    //n is the number of column
    //m is the number of row
    int arr[m][n];
    int ans [n+1][n+1]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            ans[arr[i][j]][arr[i][j-1]]=1;
            ans[arr[i][j-1]][arr[i][j]]=1;
        }
    }
    cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ans[i][j]==0)cnt++;
            // cout<<ans[i][j]<<" ";
        }
        // cout<<endl;
    }
    int realans=cnt-n;
    cout<<realans/2<<endl;
    return 0;
    }