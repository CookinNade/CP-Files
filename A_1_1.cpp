#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>s;
        for(int i=1;i<n-1;i++){
            if(s[i-1]=='1' and s[i-1]==s[i+1])s[i]='1';
        }
        ll mx=0,mn=0;
        for(int i=0;i<n;i++)if(s[i]=='1')mx++;
        for(int i=1;i<n-1;i++){
            if(s[i-1]=='1' and s[i-1]==s[i+1])s[i]='0';
        }
        for(int i=0;i<n;i++)if(s[i]=='1')mn++;
        cout<<mn<<" "<<mx<<endl;
    }
    return 0;
    }