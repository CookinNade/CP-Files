#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=0;i<2;i++){
        int a;
        cin>>a;
        mp[a]++;
    }
    for(int i=0;i<n-2;i++){
        int a;
        cin>>a;
        mp[a]++;
        auto it = --mp.end();
        int rem = 3;
        int ans = (*it).first;
        while(rem > 0){
            ans = (*it).first;
            rem -= (*it).second;
            --it;
        }
        // cout<<ans<<" "<<i<<endl;
        cout<<ans<<'\n';
    }
    return 0;
    }