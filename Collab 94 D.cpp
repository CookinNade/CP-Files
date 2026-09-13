#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    string s,f;
    cin>>s>>f;
    int j=0;int i=0;
    bool yes=false;
    set<char>st;
    st.insert('A'); st.insert('E'); st.insert('I'); st.insert('O'); st.insert('U'); st.insert('Y');
    for(int i=0;i<s.size();i++)s[i]=toupper(s[i]);
    for(int i=0;i<f.size();i++)f[i]=toupper(f[i]);
    // cout<<s<<" "<<f<<endl;
    for(;i<f.size();i++){
        if(j<s.size() and s[j]==f[i]){
            j++;
        }
        else if(j<s.size() and s[j]!=f[i] and st.find(f[i])!=st.end())continue;
        else if(j>=s.size() and st.find(f[i])!=st.end())continue;
        else {
            // cout<<f[i]<<" dd  "<<s[j]<< "\n";
            // cout<<i<<" fasdf "<<j<< "\n";
            break;
        }
    }
    // cout<<j<<" "<<i<<endl;
    if((int)f.size()==i and (int)s.size()==j)cout<<"Same";
    else cout<<"Different\n";
    return 0;
}