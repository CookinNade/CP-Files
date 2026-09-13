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
        int arr[n];ll pref[n];
        // pref[0]=1;
        ll sum=0;
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
            pref[i]=sum;
        }
        int noer=0;
        for(int i=1;i<n;i++){
            if(arr[i]>pref[i-1]){
                noer++;
                break;
            }
            else continue;
        }
        // for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<pref[i]<<" ";
        // cout<<endl;
        
        if(arr[0]!=1)cout<<"NO\n";
        else if(noer)cout<<"NO\n";
        
        else cout<<"YES\n";
    }
    return 0;
    }