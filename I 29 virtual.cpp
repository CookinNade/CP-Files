#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define double long double

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int h;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cin>>h;
    int mn = 3002;
    int ans = -1;
    for(int i=0;i<n;i++){
        if(h % arr[i] < mn){
            ans = arr[i];
            mn = h % arr[i];
        }
    }
    cout<<ans;
    return 0;
    }