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
        cin>>n;
        string s;
        map<string,int>mp;
        for(int i=0;i<n;i++){
            cin>>s;
            for(int j = 0;j<s.size();j++)s[j] = tolower(s[j]);
            mp[s]++;
        }
        int mx = 0;
        for(auto it  = mp.begin();it!=mp.end();++it){
            mx = max((*it).second,mx);
        }
        cout<<mx;
    }
    return 0;
    }