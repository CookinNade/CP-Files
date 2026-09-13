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
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n);
        int noer=0;
        for(int i=0;i<n-1;i++){
            if(i%2)if(arr[i]<arr[i+1])noer++;
        }
        if(noer)cout<<"NO\n";
        else cout<<"YES\n"; 
    }
    }