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
        cin>>a>>b;
        d=abs(a-b);
        cnt=1;
        for(int i=2;i<=d;i++){
            if(d%i==0)cnt++;
        }
        cout<<cnt<<endl;
        for(int i=0;i<a;i++){
                cout<<1<<" ";
            }
        for(int i=0;i<b;i++){
            cout<<-1<<" ";
        }
        cout<<endl;
    }
    return 0;
    }