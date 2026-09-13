#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    if(s[0] == 'f'){
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++)arr[i]--;
        string ans = "";
        for(int i=0;i<n;i++){
            ans.push_back('a' + arr[i]);
        }
        cout<<ans<<endl;
    }
    else{
        string ans;
        cin>>ans;
        cout<<ans.size()<<endl;
        ll n = (ll)ans.size();
        for(int i=0;i<n;i++){
            int j = ans[i];
            int d = 'a';
            cout<<j - d + 1<<" "; 
        }
        cout<<'\n';
    }
    return 0;
    }