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
        if(a==0 and b%2==0){
            cout<<"NO\n";
            continue;
        }
        if((a+b)%2)b--;
        else a--;
        if(a>b){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            cnt=2;
            for(int i=0;i<a;i++){
                cout<<1<<" "<<cnt<<endl;
                cout<<cnt<<" "<<cnt+1<<endl;
                cnt=cnt+2;
                b--;
            }
            for(int i=0;i<b;i++){
                cout<<1<<" "<<cnt<<endl;
                cnt++;
            }
        }
    }
    return 0;
    }