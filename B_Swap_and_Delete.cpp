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
        int cnt1=0;int cnt0=0;
        n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                cnt1++;
            }
            else cnt0++;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(cnt0>0){
                    cnt0--;
                }
                else if(cnt0==0){
                    cout<<n-i<<endl;
                    break;
                }
            }
            else if(s[i]=='0'){
                if(cnt1>0){
                    cnt1--;
                }
                else if(cnt1==0){
                    cout<<n-i<<endl;
                    break;
                }
            }
            if(i==n-1){
                cout<<0<<endl;
            }
        }
    }
    return 0;
    }