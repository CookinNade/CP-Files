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
        int arrmn[n];
        int arrmx[n];
        int mn = 1e6+10;
        int mx = -1;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++){
            mn=min(mn,arr[i]);
            arrmn[i]=mn;
        }
        for(int i=n-1;i>=0;i--){
            mx=max(mx,arr[i]);
            arrmx[i]=mx;
        }
        // for(int i=0;i<n;i++)cout<<arrmn[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<arrmx[i]<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++){
            if(arr[i]>arrmn[i] and arr[i]<arrmx[i])cout<<0;
            else cout<<1;
        }
        cout<<endl;
    }
    return 0;
    }