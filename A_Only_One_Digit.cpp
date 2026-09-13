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
        cin>>n;
        string num = to_string(n);
        r=11;
        for(int i=0;i<num.size();i++){
            r=min(r,num[i]-'0');
        }
        cout<<r<<endl;
    }
    return 0;
    }