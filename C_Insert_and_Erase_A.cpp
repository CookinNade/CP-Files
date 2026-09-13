#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s,t;
    cin>>s>>t;
    int l=0;
    int cnt=0;
    for(int i=0;i<s.length();i++){
        for(;l<t.length();l++){
            if(s[i]==t[l]){
                l++;
                break;
            }
            else if(s[i]=='A'){
                cnt++;break;
            }
            else if(t[l]=='A'){
                cnt++;
                if(t.length()-1==l){
                    cnt=-1;
                    break;
                }
            }
            else{
                cnt=-1;
                break;
            }
        }
        if(cnt==-1)break;
        if(l>=t.length() and i+1<s.length()){
            i++;
            for(;i<s.length();i++){
                if(s[i]=='A')cnt++;
                else{
                    cnt=-1;
                    break;
                }
            }
        }
    }
    if(cnt==-1){
        cout<<cnt<<endl;
        return 0;
    }
    for(;l<t.length();l++){
        if(t[l]=='A')cnt++;
        else{
            cnt=-1;
            break;
        }
    }
    cout<<cnt<<endl;
    return 0;
    }