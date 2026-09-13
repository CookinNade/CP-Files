#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        // int n;
        cin>>n;
        int one = 0;
        int zero = 0;

        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(a)one++;
            else zero++;
        }
        if(one>=zero)cout<<"Bessie\n";
        else cout<<"Elsie\n";
    }
    return 0;
    }