#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int m;
        cin>>n>>m;
        bool arr[26];
        fill(arr,arr+26,false);
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            arr[s[0] - 'a'] = true;
        }
        bool yes = true;
        for(int i=0;i<m;i++){
            string s;
            cin>>s;
            for(int j = 0;j<(int)s.size();j++){
                if(arr[s[j] - 'A'])continue;
                else{
                    yes = false;
                    break;
                }
            }
        }
        if(yes)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }