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
        int fcnt=0;int tcnt=0;int ncnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='F')fcnt++;
            else if(s[i]=='T')tcnt++;
            else if(s[i]=='N')ncnt++;
        }
        s.erase(remove(s.begin(),s.end(),'F'),s.end());
        s.erase(remove(s.begin(),s.end(),'T'),s.end());
        s.erase(remove(s.begin(),s.end(),'N'),s.end());
        for(int i=1;i<=tcnt;i++){
            cout<<'T';
        }
        for(int i=1;i<=ncnt;i++){
            cout<<'N';
        }
        for(int i=1;i<=fcnt;i++){
            cout<<'F';
        }
        cout<<s<<endl;
    }
    return 0;
    }