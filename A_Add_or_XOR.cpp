#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x,y; 
    cin>>t;
    string s;
    while (t--){
        cin>>a>>b>>x>>y;
        if(a%2==0 and a>b){
            cout<<-1<<endl;
        }
        else if(a%2==1 and a-1>b){//think we forgot the case for a-1==b
            cout<<-1<<endl;
        }
        else if(a%2==1 and a-1==b){
            cout<<y<<endl;
        }
        else if(a%2==0 and a<=b){
            int del = b-a;
            if(x<=y){
                cout<<del*x<<endl;
            }
            else {
                cout<<(del/2)*x + (del-del/2)*y<<endl;
            }
        }
        else if(a%2==1 and a<=b){
            int del = b-a;
            if(x<=y){
                cout<<del*x<<endl;
            }
            else {
                cout<<(del/2)*y + (del-del/2)*x<<endl;
            }
        }
    }
    return 0;
    }