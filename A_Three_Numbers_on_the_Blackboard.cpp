#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int a,b,c;
        cin>>a>>b>>c;
        int arr[3] = {a,b,c};
        sort(arr,arr+3);
        int mn = arr[2] - arr[0];
        arr[2] = arr[1] + arr[0];
        mn = min(mn , arr[2] - arr[0]);
        cout<<mn<<'\n';
    }
    return 0;
    }