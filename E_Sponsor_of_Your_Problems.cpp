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
        int breakl=1;
        int breakr=1;
        cin>>l>>r;
        cnt=0;
        string sl = to_string(l);
        string sr = to_string(r);
        for(int i=0;i<sl.size();i++){
            int cl= sl[i]-'0';
            int cr= sr[i]-'0';
            if(cr-cl==0 and breakr==1 and breakl==1){
                cnt=cnt+2;
            }
            else if(cr-cl==1 and breakr==1 and breakl==1){
                cnt++;
                breakl=0;
            }
            else if(cr-cl>1 and breakr==1 and breakl==1){
                breakr=0;
                breakl=0;
                break;
            }
            else if(breakr==1 and breakl==0){
                if(cr==0){
                    cnt++;
                }
                else{
                    breakr=0;
                    break;
                }
            }
        }
        breakl=1;
        breakr=1;
        int cntr=0;
        for(int i=0;i<sl.size();i++){
            int cl= sl[i]-'0';
            int cr= sr[i]-'0';
            if(cr-cl==0 and breakr==1 and breakl==1){
                cntr=cntr+2;
            }
            else if(cr-cl==1 and breakr==1 and breakl==1){
                cntr++;
                breakr=0;
            }
            else if(cr-cl>1 and breakr==1 and breakl==1){
                breakr=0;
                breakl=0;
                break;
            }
            else if(breakl==1 and breakr==0){
                if(cl==9){
                    cntr++;
                }
                else{
                    breakl=0;
                    break;
                }
            }
        }
        cout<<min(cnt,cntr)<<endl;
    }
    return 0;
    }