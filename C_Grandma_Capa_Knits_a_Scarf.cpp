#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>s;
        string a=s;
        reverse(a.begin(),a.end());
        char c='a';
        int cnt; int ans=1e9;
        for(int i=0;i<26;c++,i++){
            cnt=0;
            int r=n-1; int l=0; string shuru="", shesh="";        
            for(;l<r;){
                // if(c=='r')cout<<l+1<<" "<<r+1<<endl;
                if(s[l]!=c and s[r]!=c){
                    shuru.push_back(s[l]);
                    shesh.push_back(s[r]);
                    l++; r--;
                }
                else if(s[l]==c and s[r]!=c){
                    cnt++;
                    l++;
                }
                else if(s[r]==c and s[l]!=c){
                    cnt++;
                    r--;
                }
                else{
                    shuru.push_back(s[l]);
                    shesh.push_back(s[r]);
                    l++; r--;
                }
            }
            reverse(shesh.begin(),shesh.end());
            string test = shuru+shesh;
            string test2=test;
            reverse(test2.begin(),test2.end());
            if(test==test2){
                // cout<<c<<endl;
                // cout<<cnt<<endl;
                ans=min(ans,cnt);
            }
        }
        if(ans==1e9)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
    }