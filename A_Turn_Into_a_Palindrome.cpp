#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        int cnt = 0;
        for(int i=0;i<n/2;i++){
            if(s[i] != s[n-1-i]){
                if(s[i]!=c)cnt++;
                if(s[n-1-i]!=c)cnt++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
    }