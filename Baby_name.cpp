#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int best(string s){
    int n = (int)s.size();
    int i = 0;
    int j = 1;
    for(;i<n and j<n;){
        for(int k = 0;;k++){
            if(j + k == n)return i;
            if(s[i+k]==s[j+k])continue;
            else if(s[i+k] > s[j+k]){
                j = j+k+1;
                break;
            }
            else{
                i = max(i+k+1,j);
                j = i+1;
                break;
            }
        }
    }
    return i;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string m,f;
    cin>>f>>m;
    int indm = best(m);
    int indf = best(f);
    string ans = "";
    ans.push_back(f[indf]);
    for(int i=indf+1;i<(int)f.size();i++){
        if(f[i] >= m[indm])ans.push_back(f[i]);
        else break;
    }
    for(int i=indm;i<(int)m.size();i++)ans.push_back(m[i]);
    cout<<ans;
    return 0;
    }