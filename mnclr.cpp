#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    string s;
    cin>>s;
    for(int i=0;i<(int)s.size();i++){
        cout<<s[i];
        if(i!=s.size() - 1)cout<<'o';
    }
    return 0;
    }