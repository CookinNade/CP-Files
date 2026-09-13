#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        string s;
        cin>>n>>s;
        // cout<<sz<<endl;
        int cnt = 1;
        for(int i=0;i<n-1;i++)if(s[i] != s[i+1])cnt++;
        if(cnt>=3 or cnt ==1)cout<<1<<endl;
        else cout<<2<<endl;

        
    }
    return 0;
    }