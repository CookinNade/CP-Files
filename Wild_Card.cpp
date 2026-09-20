#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    string t;
    cin>>s>>t;
    bool yes = true;
    for(int i=0;i<n;i++){
        if(t[i] == '*')continue;
        yes &= (t[i] == s[i]);
    }
    if(yes)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
    }