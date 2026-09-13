#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
vector<string> v; 
void GG(int n, int k, int open, char &ans,string &s,int req){    
    if(n<=3){
        ans=v[n-1][k-1];
        return;
    }
    ll sum=0;
    for(auto x:v[v.size()-1]){
        if(open == n-1){
            sum=sum+2;
        }
        if (x=='0') s.append("01");
        else s.append("10");
        if(sum>=req){
            ans=s[req-1];
            return; 
        }
    }
    v.push_back(s);
    s="";
    GG(n,k,open+1,ans,s,req);
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,t,k; char ans;
    cin>>n>>k;string s;
    v.push_back("0"); v.push_back("01") ; v.push_back("0110") ;int open =3;
    int req = (k/2)+(k%2);
    GG(n,k,open,ans,s,req);
    int realans = ans-'0';
    if(n<=3)cout<<realans<<endl;
    else if(realans){
        if(k%2)cout<<1<<endl;
        else cout<<0<<endl;
    }
    else{
        if(k%2)cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}