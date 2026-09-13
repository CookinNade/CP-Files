#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>s;
        int n=s.size();
        int a=-1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                a=i+1;
                break;
            }
        }
        if(a==-1)cout<<"YES\n";
        else{
            b=-1;
            d=a;
            for(;a<n-1;a++){
                if(s[a]==s[a+1]){
                    b=a;
                    break;
                }
            }
            if(b==-1)cout<<"YES\n";
            else{
                string l,r;
                for(int i=0;i<d;i++)l.push_back(s[i]);
                for(int i=0;i<d;i++)r.push_back(s[i]);
                for(;d<=b;d++){
                    l.push_back(s[d]);
                    if(s[d]=='a')r.push_back('b');
                    else r.push_back('a');
                }
                for(int i=b+1;i<n;i++)l.push_back(s[i]);
                for(int i=b+1;i<n;i++)r.push_back(s[i]);
                int no=0;
                for(int i=0;i<n-1;i++){
                    if(r[i]==r[i+1]){
                        no++;
                        break;
                    }
                }
                if(no){
                    no=0;
                    for(int i=0;i<n-1;i++){
                        if(r[i]==r[i+1]){
                            no++;
                            break;
                        }
                    }
                    if(no)cout<<"NO\n";
                    else cout<<"YES\n";
                }
                else{
                    cout<<"YES\n";
                }
            }
        }
    }
    return 0;
    }