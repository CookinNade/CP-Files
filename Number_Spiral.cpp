#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x,y; 
    cin>>t;
    string s;
    while (t--){
        cin>>x>>y;
        if(x==y){
            cout<<x*x-x+1<<endl;
        }
        else if(x>y and x%2==0){
            cout<<x*x-y+1<<endl;
        }
        else if(x>y and x%2==1){
            cout<<(x-1)*(x-1)+y<<endl;
        }
        else if(y>x and y%2==1){
            cout<<y*y-x+1<<endl;
        }
        else if(y>x and y%2==0){
            cout<<(y-1)*(y-1)+x<<endl;
        }
    }
    return 0;
    }