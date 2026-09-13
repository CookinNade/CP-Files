#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>s;
        cnt=1;
        vector<char>v;
        int yes=0;
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1])cnt++;
            if(s[i]==s[i+1])yes++;
        }
        if(yes and s[0]!=s[n-1])cnt++;
        cout<<cnt<<endl;
    }
    return 0;
    }