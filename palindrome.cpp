#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
string s;
int n;
bool pal(int i, int j){
    if(i>=j)return true;
    return (s[i] == s[j]) && pal(i+1,j-1);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    s = "";
    getline(cin, s);
    n = (int)s.size();
    if(pal(0,n-1))cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}