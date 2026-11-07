#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int n;
string s;
void rev(int i){
    if(i == n)return;
    rev(i+1);
    cout<<s[i];
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    n = (int)s.size();
    rev(0);    
    return 0;
}