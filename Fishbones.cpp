#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    set<int>g[26];
    pair<int,int>order[n];
    for(int i=0;i<n;i++)cin>>order[i].first>>order[i].second;
    int m;
    cin>>m;
    string words[m];
    for(int i=0;i<m;i++)cin>>words[i];
    for(int i=0;i<m;i++){
        int sz = (int)words[i].size();
        for(int j=0;j<sz;j++){
            int letter = words[i][j] - 'a';
            g[letter].insert({sz,j+1});
        }
    }
    
    return 0;
    }