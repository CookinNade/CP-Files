#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,sa,sb,d;
    cin>>a>>b>>sa>>sb>>d;
    int t = 0;
    while(a!=b){
        a = a + sa;
        if(a > d)a -= d;
        b = b + sb;
        if(b > d)b -= d;
        cout<<a<<" "<<b<<endl;
        t++;
    }
    cout<<t<<endl;
    return 0;
    }