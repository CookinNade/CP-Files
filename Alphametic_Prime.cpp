#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const ll N = 1e7+2;
bool notprime[N];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i=2;i*i<N;i++){
        if(notprime[i])continue;
        for(int j = i*2; j<=N; j = j+i){
            notprime[j] = true;
        }
    }
    notprime[1] = true;
    // for(int i=1;i<=13;i++){
    //     cout<<i<<" ";
    //     if(notprime[i])cout<<"NO\n";
    //     else cout<<"YES\n";
    // }
    string s;
    cin>>s;
    int dig = (int)s.size();
    int ans = 1;
    for(int i=0;i<dig-1;i++)ans*=10;
    bool yes = false;
    map<char,char> mpci;
    map<char,char> mpic;
    ll bans = -1;
    for(int i = ans; i < ans*10; i++){
        if(notprime[i])continue;
        string num = to_string(i);
        bool hobe = true;
        mpic.clear();
        mpci.clear();
        for(int j = 0;j<(int)num.size();j++){
            if(mpci.find(s[j]) != mpci.end()){
                if(mpci[s[j]] != num[j]){
                    hobe = false;
                    break;
                }
            }
            else{
                mpci[s[j]] = num[j];
            }
            if(mpic.find(num[j]) != mpic.end()){
                if(mpic[num[j]] != s[j]){
                    hobe = false;
                    break;
                }
            }
            else{
                mpic[num[j]] = s[j];
            }
        }
        if(hobe){
            bans = i;
            break;
        }
    }
    cout<<bans<<'\n';
    return 0;
    }