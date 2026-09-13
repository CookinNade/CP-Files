#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

bool ase[26][26];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    bool yes = true;
    int cnt[26] = {};
    for(int i=0;i<n-1;i++){
        for(int j = 0; j < (int)s[i].size() ; j++){
            if(j>=(int)s[i+1].size()){
                yes = false;
                break;
            }
            if(s[i][j] != s[i+1][j]){
                // cout<<s[i][j] <<" "<<s[i+1][j]<<endl;
                int a = s[i][j] - 'a';
                int b = s[i+1][j] - 'a';
                if(!ase[a][b]) cnt[b]++;
                ase[a][b] = true;
                break;
            }
        }
        if(!yes)break;
    }
    if(!yes){
        cout<<"Impossible";
        return 0;
    }
    string ans = "";
    queue<int>q;
    for(int i=0;i<26;i++)if(cnt[i] == 0)q.push(i);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        ans.push_back(char(c+'a'));
        for(int i = 0; i<26; i++){
            if(!ase[c][i])continue;
            cnt[i]--;
            if(cnt[i] == 0){
                q.push(i);
            }
        }
    }
    if((int)ans.size() != 26)cout<<"Impossible";
    else cout<<ans;
    return 0;
    }