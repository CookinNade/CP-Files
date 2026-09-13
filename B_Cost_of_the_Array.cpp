#include<bits/stdc++.h>
 
using namespace std;
// typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        cnt=0;int j=1;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(k!=n){
            for(int i=1;i<n;i++){
                if(arr[i]==1){
                    cnt++;
                }
                else if(arr[i]!=1){
                    if(cnt>=n-k+1){
                        j=2;
                    }
                    else j=1;
                    break;
                }
            }
        }
        else if(n==k){
            for(int i=1;i<n;i=i+2){
                if(j==arr[i]){
                    j++;
                }
                else break;
            }
        }
        if(cnt==n-1){
            cout<<2<<endl;}
        // else if(arr[0]!=1 and cnt==n-1){
        //     cout<<2<<endl;
        // }   
        else cout<<j<<endl;
    }
    return 0;
    }