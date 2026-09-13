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
        cin>>s;
        cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
    }