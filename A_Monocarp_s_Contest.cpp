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
        int easy = 0;
        int hard = 0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr[i] = a;
            if(a)hard++;
            else easy++;
        }
        if(easy < 2){
            cout<<-1<<'\n';
            continue;
        }
        cout<<arr[0] + arr[n-1]<<'\n';

    }
    return 0;
    }