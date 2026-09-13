#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    // cin>>t;
    string s;
    // while (t--){
        cin>>s;
        cnt=1;
        int maxcnt=1;
        for(int i=1;i<s.size();i++){
            if(s[i-1]==s[i]){
                cnt++;
                maxcnt=max(cnt,maxcnt);
            }
            else {
                maxcnt=max(cnt,maxcnt);
                cnt=1;
            }
        }
        cout<<maxcnt<<endl;
    // }
    return 0;
    }