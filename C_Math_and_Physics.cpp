#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int arr[n];
        map<int,int>mp;
        mp[1] = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]]++;
        }
        if((int)mp.size() == 1 and arr[0] == 1){
            cout<<-1<<'\n';
            continue;
        }
        if(n==2){
            cout<<arr[0]+arr[1]-1<<'\n';
            continue;
        }
        bool yes = false;
        for(int i=1;i<n-1;i++)if(arr[i]>1)yes=true;
        if(yes)cout<<accumulate(arr,arr+n,0)-1<<'\n';
        else if(mp[1] == n-1)cout<<accumulate(arr,arr+n,0)-mp[1]<<'\n';
        else cout<<accumulate(arr,arr+n,0)-mp[1]-1<<'\n';
    }
    return 0;
    }