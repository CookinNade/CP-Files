#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,d,cnt,l,k,x; 
    t=1;
    string s;
    while (t--){
        cin>>n>>k>>s;
        string ans="z";
        for(int i=1;i<k;i++)ans.push_back('z');
        string test;
        for(int i=0;i<n and i<k;i++){
            test.push_back(s[i]);
            string r="";
            for(int j=0;j<k/(int)test.size();j++){
                for(int q=0;q<test.size();q++)r.push_back(test[q]);
            }
            for(int j=0;j<k%(int)test.size();j++)r.push_back(test[j]);
            if(r<=ans)ans=r;
        }
        cout<<ans<<endl;
    }
    return 0;
    }