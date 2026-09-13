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
    string s,q,fin;
    while (t--){
        cin>>n>>s>>m>>q>>fin;
        int back =0; int front =0;
        for(int i=0;i<m;i++){

            if(fin[i]=='D'){
                s=s + q[i];
            }
            else s = s= q[i] + s;
        }
        cout<<s<<endl;
    }
    return 0;
    }