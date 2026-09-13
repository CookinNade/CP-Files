#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,a,b,d,cnt,r,l,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>s;
        char c ='a';
        string l2 ="aa";
        string l3 ="aaa";
        string l4 = "aaaa";
        string ans="nothing";
        int f =0;
        int yes=0;
        for(int i=0;i<26;i++){
            size_t pos = s.find(c);
            if(pos==string::npos){
                yes++;
                break;
            }
            c++;
        }
        if(yes==0){
            for(int i=0;i<26;i++,l2[0]++){
                l2[1]='a';
                for(int j=0;j<26;j++,l2[1]++){
                    // cout<<l2<<" ";
                    size_t pos = s.find(l2);
                    if(pos==string::npos){
                        yes++;
                        ans=l2;
                        break;
                    }
                }cout<<endl;
                if(yes)break;
            }
        }
        else {
            cout<<c<<endl;
            continue;
        }
        if(yes==0){
            for(int i=0;i<26;i++,l3[0]++){
                l3[1]='a';
                for(int j=0;j<26;j++,l3[1]++){
                    l3[2]='a';
                    for(int k=0;k<26;k++,l3[2]++){
                        size_t pos = s.find(l3);
                        if(pos==string::npos){
                            yes++;
                            ans=l3;
                            break;
                        }
                        if(yes)break;
                    }
                    if(yes)break;
                }
                if(yes)break;
            }
        }
        if(yes==0){
            for(int i=0;i<26;i++,l4[0]++){
                l4[1]='a';
                for(int j=0;j<26;j++,l4[1]++){
                    l4[2]='a';
                    for(int k=0;k<26;k++,l4[2]++){
                        l4[3]='a';
                        for(int m=0;m<26;m++,l4[3]++){
                            size_t pos = s.find(l3);
                            if(pos==string::npos){
                                yes++;
                                ans=l4;
                                break;
                            }
                        }
                        if(yes)break;
                    }
                    if(yes)break;
                }
                if(yes)break;
            }
            if(yes)break;
        }
        cout<<ans<<endl;
        
        
    }
    return 0;
    }