#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cnt=0;
    sort(arr,arr+n);
    l=0;r=1;
    for(;l<n-1 and r<n;){
        // cout<<arr[l]<<" "<<arr[r]<<endl;
        if(abs(arr[l]-arr[r])<k){
            // cout<<arr[l]<<" "<<arr[r]<<endl;
            cnt++;
            r++;
        }
        else{
            l=r;
            r++;
        }
    }
    cout<<cnt<<endl;
    return 0;
    }