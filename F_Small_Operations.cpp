#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d; 
    cin>>t;
    string s;
    while (t--){
        cin>>a>>b>>c>>d;
        int gk = min(a,c);
        int fk = min(b,d);
        if(gk>=fk){
            cout<<"Gellyfish"<<endl;
        }
        else cout<<"Flower"<<endl;
    }
    return 0;
    }