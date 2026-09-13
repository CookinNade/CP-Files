#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;
    string s1;
    cin>>s1;
    string target(n,'0');

    string s2=s1;
    for(ll i=1;i<n;i++){
      if(i%2==1) target[i]='1';
    }

    ll op1=0;

    for(ll i=1;i<n;i++){
      if(s1[i-1]!=target[i-1]){
        s1[i-1]=(s1[i-1]=='0')?'1':'0';
        s1[i]=(s1[i]=='0')?'1':'0';
        if(i<n-1){
          s1[i+1]=(s1[i+1]=='0')?'1':'0';
        }

        op1++;
      }
    }

    ll op2=1;
    s2[0]=(s2[0]=='0')?'1':'0';
    s2[1]=(s2[1]=='0')?'1':'0';
    for(ll i=1;i<n;i++){
      if(s2[i-1]!=target[i-1]){
        s2[i-1]=(s2[i-1]=='0')?'1':'0';
        s2[i]=(s2[i]=='0')?'1':'0';
        if(i<n-1){
          s2[i+1]=(s2[i+1]=='0')?'1':'0';
        }

        op2++;
      }
    }

    if(s1==target && s2==target)
      cout<<min(op1,op2)<<endl;
    else if(s1==target)
      cout<<op1<<endl;
    else if(s2==target) 
      cout<<op2<<endl;
    else 
      cout<<-1<<endl;
  }

}