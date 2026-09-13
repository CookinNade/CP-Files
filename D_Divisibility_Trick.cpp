#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int dig(int n){
    int ans=0;
    while(n>0){
        ans=ans+n%10;
        n=n/10;
    }
    return ans;
}
int main () {
    int a;
    cin>>a;
    int m=dig(a);
    int l=lcm(a,m);
    string s=to_string(a);
    // cout<<l<<endl;
    for(int i=0;i<l;i++)cout<<s;
    return 0;
}