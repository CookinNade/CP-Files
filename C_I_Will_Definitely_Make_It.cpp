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
        for(int i=0;i<n;i++)cin>>arr[i];
        a = arr[k-1];
        sort(arr,arr+n);
        auto it = lower_bound(arr,arr+n,a);
        // cout<<it<<endl;
        int j=it-arr;
        int adv=a-1;
        int noer=0;
        // cout<<adv<<endl;
        for(int i=j+1;i<n;i++){
            if(arr[i]-arr[i-1]>adv+1) noer++;
            else continue;
        }
        cout<<(noer? "NO\n" :"YES\n");
    }
    return 0;
    }