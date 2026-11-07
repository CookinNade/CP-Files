#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    vector<pair<char,int>>v;
    int cnt = 0;
    char c = s[0];
    int n = (int)s.size();
    for(int i=0;i<n;i++){
        
        if(c == s[i])cnt++;
        else{
            v.push_back({c,cnt});
            c = s[i];
            cnt = 1;
        }
    }
    v.push_back({c,cnt});
    if((int)v.size() % 2 == 0){
        cout<<0<<'\n';
        return 0;
    }
    for(int i=0;i<(int)v.size();i++){
        // cout<<i<<" "<<v[i].first<<" "<<v[i].second<<endl;
    }
    bool yes = true;
    int ken = (int)v.size() / 2;
    for(int i = 1; i<=ken; i++){
        if(v[ken - i].first == v[ken + i].first and v[ken - i].second + v[ken + i].second >= 3)continue;
        else{
            // cout<<i<<" "<<ken - i<<" "<<ken+i<<" "<<v[ken - i].first<<" "<<v[ken + i].first<<'\n';
            yes = false;
            break;
        }
    }
    if(v[ken].second >=2 and yes)cout<<v[ken].second+1;
    else cout<<0;
    return 0;
    }