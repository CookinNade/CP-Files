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
        cin>>s;
        n=s.size();
        int lcnt=0,rcnt=0,rpos=n+5,lpos=-1,ast=0;
        for(int i=0;i<n;i++){
            if(s[i]=='<'){
                lcnt++;
                lpos=i;
            }
            else if(s[i]=='>'){
                rcnt++;
                rpos=min(i,rpos);
            }
            else {
                ast++;
            }
        }
        int inf=0;
        int lenl=0, lenr=0;
        if(ast==1){
            r=0; 
            for(int i=0;i<n;i++){
                if(s[i]=='*'){
                    r++; 
                }
                else if(r==0){
                    if(s[i]=='>'){
                        inf++; break;
                    }
                    else lenl++;
                }
                else if(r){
                    if(s[i]=='<'){
                        inf++; break;
                    }
                    else lenr++;
                }
            }
        }
        if(n==1)cout<<1<<endl;
        else if(lpos>rpos)cout<<-1<<endl;
        else if(ast==1 and inf)cout<<-1<<endl;
        else if(ast==1 and inf==0)cout<<max(lenl,lenr)+1<<endl;
        else if(ast)cout<<-1<<endl;
        else{
            l=0;
            for(int i=0;i<n;i++){
                if(s[i]=='<')l++;
                else break;
            }
            cout<<max(l,n-l)<<endl;
        }
    }
    return 0;
    }