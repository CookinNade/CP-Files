#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n,greater<int>());
        bool yes = true;
        for(int i=0;i<n-2;i++){
            if(arr[i]%arr[i+1]==arr[i+2])continue;
            else {
                yes=false;
                break;
            }
        }
        if(yes)cout<<arr[0]<<" "<<arr[1]<<'\n';
        else cout<<-1<<'\n';

    }
    return 0;
    }