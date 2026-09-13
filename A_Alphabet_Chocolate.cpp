#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    string s;
    cin>>s;
    if((int)s.size()%2){
        cout<<s[(int)s.size()/2];
    }
    else cout<<":)";
    return 0;
    }