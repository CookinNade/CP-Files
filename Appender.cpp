#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int n = (int)s.size() -1;
    if(s[n] == 'e')cout<<s<<"r";
    else cout<<s<<"er";
    return 0;
    }