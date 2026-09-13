#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>s;
        int n = (int)s.size();
        set<char>st;
        for(int i=0;i<n;i++)st.insert(s[i]);
        if((int)st.size() == 1)cout<<0<<'\n';
        else cout<<2*n - 2<<'\n';
    }
    return 0;
    }