#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>s;
        int no=0;
        for(int i=0;i<n;i++){
            // cout<<i<<endl;
            for(int j=0;j<n;j++){
                if(s[j]=='*')continue;
                for(int l=j+1;l<n;l++){
                    // cout<<j<<" "<<l<<endl;
                    if(s[l]=='*')continue;
                    if(s[j]==s[l]){
                        s[j]='*';
                        s[l]='*';
                        j=l;
                        break;
                    }
                    else{
                        j=l-1;
                        break;
                    }
                }
            }
        }
        // cout<<s<<endl;
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                no++;
                break;
            }
        }
        if(no)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
    }