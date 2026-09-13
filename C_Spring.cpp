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
        cin>>a>>b>>c>>d;
        n=(d/a) - (d/lcm(a,b)) -  (d/lcm(a,c)) + (d/lcm(a,lcm(b,c)));
        n=n*6;
        k=(d/lcm(a,b)) +  (d/lcm(a,c)) - 2*(d/lcm(a,lcm(b,c)));
        n=n + k*3;
        k=(d/lcm(a,lcm(b,c)));
        n = n + k*2;
        cout<<n<<" ";
        swap(a,b);


        n=(d/a) - (d/lcm(a,b)) -  (d/lcm(a,c)) + (d/lcm(a,lcm(b,c)));
        n=n*6;
        k=(d/lcm(a,b)) +  (d/lcm(a,c)) - 2*(d/lcm(a,lcm(b,c)));
        n=n + k*3;
        k=(d/lcm(a,lcm(b,c)));
        n = n + k*2;
        
        swap(a,b);
        swap(a,c);

        cout<<n<<" ";
        n=(d/a) - (d/lcm(a,b)) -  (d/lcm(a,c)) + (d/lcm(a,lcm(b,c)));
        n=n*6;
        k=(d/lcm(a,b)) +  (d/lcm(a,c)) - 2*(d/lcm(a,lcm(b,c)));
        n=n + k*3;
        k=(d/lcm(a,lcm(b,c)));
        n = n + k*2;
        cout<<n<<" ";
        cout<<endl;
    }
    return 0;
    }