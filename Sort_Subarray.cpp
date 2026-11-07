#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i]; 
    for(int i=0;i<n-1;i++){
        if(i+k>n and arr[i] > arr[i+1]){
            sort(arr+n-k, arr+n);
            break;
        }
        else if(arr[i] > arr[i+1]){
            sort(arr+i,arr+i+k);
            break;
        }
    }
    if(is_sorted(arr,arr+n))cout<<"Yes";
    else cout<<"No";
    return 0;
    }