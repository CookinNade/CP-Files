#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    // cin>>t;
    t = 1;
    while (t--){
        string s;
        cin>>s;
        for(int i=0;i<(int)s.size();i++){
            if(s[i] != 'A')s[i] = '.';
        }
        cout<<s;
    }
    return 0;
    }