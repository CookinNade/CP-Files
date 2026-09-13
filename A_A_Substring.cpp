#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    string s;
    cin>>n>>a>>b>>s;
    for(int i=a;;i++){
        cout<<s[i];
        if(i==s.size()-b-1)break;
    }cout<<endl;
    return 0;
    }