#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        string p,q;
        cin>>p>>q;
        map<char,int>mp;
        for(int i=0;i<n;i++)mp[p[i]]++;
        for(int i=0;i<m;i++)mp[q[i]]--;
        bool yes = true;
        for(auto it = mp.begin();it!=mp.end();++it){
            char c = (*it).first;
            int f = (*it).second;
            if(c == 's' or c=='i' or c == 'x'){
                if(f == 1)continue;
                else{
                    yes = false;
                    break;
                }
            }
            else if(f!=0){
                yes = false;
                break;
            }
        }
        if(yes)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }