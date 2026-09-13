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
        string s;
        cin>>s;
        char c = s[0];
        cnt = 1;
        for(int i=1;i<n;i++){
            if(c==s[i])continue;
            cnt++;
            c=s[i];
        }

        int ans = 0;
        for(int i=1;i<n-1;i++){
            char d = s[i];
            if(d==s[i-1] or d==s[i+1])continue;
            if(s[i-1] == s[i+1]) ans = max(ans,2);
            if(s[i-1] != s[i+1]) ans = max(ans,1);
        }
        cout<<cnt-ans<<'\n';
    }
    return 0;
    }