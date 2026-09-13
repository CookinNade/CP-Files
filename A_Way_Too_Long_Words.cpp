#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>n;
    string s;
    while (n--){
        cin>>s;
        m=s.size();
        if(m<=10){
            cout<<s<<endl;
        }
        else{
            cout<<s[0]<<m-2<<s[m-1]<<endl;
        }
    }
    return 0;
    }