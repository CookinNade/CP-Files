#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

void msort(int l, int r, vector<int>&arr){
    if(l == r)return;
    int m = (l+r)/2;
    msort(l,m,arr);
    msort(m+1,r,arr);
    int i = l;
    int j = m+1;
    int sorted[r-l+1];
    int k = 0;
    for(;k<r-l+1;k++){
        if(i>m or j>r)break;
        if(arr[i] < arr[j]){
            sorted[k] = arr[i];
            i++;
        }
        else{
            sorted[k] = arr[j];
            j++;
        }
    }
    for(;i<=m;i++,k++)sorted[k] = arr[i];
    for(;j<=r;j++,k++)sorted[k] = arr[j];
    for(int b=l;b<=r;b++)arr[b] = sorted[b-l];
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    msort(0,n-1,arr);
    int k;
    cin>>k;
    cout<<arr[k-1]<<'\n';
    return 0;
}