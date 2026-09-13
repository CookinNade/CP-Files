#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>a>>b;
    n=0;
    vector<int>v;
    v.push_back(b);
        while(a!=b and b>=a){
        if(b%10==1){
            b--;
            b=b/10;
            v.push_back(b);
        }
        else if(b%2==1){
            n++; break;
        }
        else{
            b=b/2;
            v.push_back(b);
        }
        if(b<a or a==b){
            break;
        }
    }
    if(n or a!=b)cout<<"NO\n"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<v.size()<<endl;
        for(int i=v.size()-1;i>=0;i--){
            cout<<v[i]<<" ";
        }cout<<endl;
    }
    return 0;
    }