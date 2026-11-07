#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

ll n,k;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<string, int> mp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s]++;
    }
    map<string, int> val;
    val["red"] = 1; val["yellow"] = 2; val["green"] = 3; val["brown"] = 4; 
    val["blue"] = 5; val["pink"] = 6; val["black"] = 7;
    if(mp.size() == 1 and mp.find("red")!=mp.end()){
        cout<<1;
        return 0;
    }
    int mx = -1;
    for(auto it = mp.begin();it!=mp.end();++it){
        mx = max(mx , val[(*it).first]);
    }
    ll ans = mp["red"] * mx;
    for(auto it = mp.begin();it!=mp.end();++it){
        ans += val[(*it).first] * (*it).second;
    }
    cout<<ans;
    return 0;
    }