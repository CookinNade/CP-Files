#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>s;
        char c,d;
        n=s.length();
        l=0;r=n-1;
        if(n==1){
            if(s[0]!='b')cout<<"YES\n";
            else cout<<"NO\n";
            continue;
        }
        int no=0;
        for(int i=0;i<n;i++){
            if(i==0){
                if(s[i]=='a'){
                    l++;
                }
                else if(s[i]=='b'){
                    if(n%2)r--;
                    else{
                        no++; break;
                    }
                }
            }
            else if(i!=n-1){
                if(s[i]=='a'){
                    if(s[l]=='a')l++;
                    else if(s[r]=='a')r--;
                    else{
                        no++;
                        break;
                    }
                }
                else if(s[i]=='b'){
                    if(s[l]=='b')l++;
                    else if(s[r]=='b')r--;
                    else{
                        no++;
                        break;
                    }
                }
                else{
                    if(s[l]==s[r]){
                        l++;
                    }
                    else{
                        c=s[i-1];
                        d=s[i+1];
                        if(c==d){
                            if(c!=s[l])l++;
                            else if(c!=s[r])r--;
                            else {
                                no++;
                                break;
                            }
                        }
                        else{
                            if(s[l+1]==s[i+1])l++;
                            else if(s[r-1]==s[i=1])r--;
                            else{
                                no++;
                                break;
                            }
                        }
                    }
                }
            }
            else{
                if(s[i]!='?'){
                    if(s[l]!=s[i]){
                        no++;
                        break;
                    }
                }
            }
        }
    }
    return 0;
    }