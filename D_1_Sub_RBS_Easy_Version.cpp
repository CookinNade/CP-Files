#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,k;
    cin>>t;
    string s;
    while (t--){
        cin>>n>>s;
        bool yes = false;
        int f = 0;
        for(int i=0;i<n-1;i++){
            if(s[i]==')' and s[i+1]=='(') f++;
            if(f){
                for(int j = i+2; j<n; j++){
                    if(s[j] == '('){
                        // cout<<j<<endl;
                        yes = true;
                        break;
                    }
                }
                break;
            } 
        }
        if(yes)cout<<n-2<<'\n';
        else cout<<-1<<'\n';
    }
    return 0;
    }