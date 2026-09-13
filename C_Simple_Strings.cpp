#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n; 
    // cin>>t;
    // while (t--){
    // }
    string s;
    cin>>s; n=s.size();
    if(n<3){
        if(n==1) cout<<s<<endl;
        else{
            if(s[0]!=s[1]) cout<<s<<endl;
            else{
                s[0]=s[0]+1;
                if(s[0]=='{'){
                    for(int j=1;s[0]==s[1] or s[0]=='{';) s[0]=s[0]-1;
                }
                cout<<s<<endl;
            }
        }
    }
    else{
        for(int i=1;i<n;i++){
            if(i==n-1){
                if(s[i-1]==s[i]){
                    char a = s[i-1];
                    for(int j=1;s[i]==a;) s[i]=s[i]+j;
                    if(s[i]=='{'){
                        for(int j=1; s[i]==a or s[i]=='{';) s[i]=s[i]-j;
                    }
                }
                break;
            }
            else if(s[i-1]==s[i]){
                char a = s[i-1];
                char b = s[i+1];
                for(int j=1; s[i]==a or s[i]==b;) s[i]=s[i]+j;
                if(s[i]=='{'){
                    for(int j=1; s[i]==a or s[i]==b or s[i]=='{';) s[i]=s[i]-j;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
    }