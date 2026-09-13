#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<pair<int,int>>v;
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            if(i != a)v.push_back({i,a});
        }
        sort(v.begin(),v.end());
        int last = n+1;
        bool yes = true;
        for(int i=0;i<(int)v.size();i++){
            if(last > v[i].second){
                last = v[i].second;
            }
            else{
                yes = false;
                break;
            }
        }
        if(yes)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
    }