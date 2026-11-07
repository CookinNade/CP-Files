#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
bool yes(char c){
    if(c == '+' or c=='*' or c == '-' or c == '/')return true;
    return false;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll a = stoll(s);
    ll b = 0;
    for(int i=0;i<n-1;i++){
        cin>>s;    
        if(s.size() == 1 and yes(s[0])){
            if(s[0] == '+') a = a + b;
            if(s[0] == '-') a = a - b;
            if(s[0] == '*') a = a * b;
            if(s[0] == '/') a = a / b;
            b = 0;
            continue;
        }
        b = stoll(s);
        
    }
    cout<<a<<'\n';
    
    
    return 0;
    }