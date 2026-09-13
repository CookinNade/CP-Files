#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,mex; 
    cin>>t;
    string s;
    while (t--){
        char x;
        cin>>n>>x>>s;
        vector<int>non;
        cnt=0;int cntl=0;mex=0;
        for(int i=0;i<n;i++){
            if(s[i]!=x and i!=n-1){
                cnt++;
                non.push_back(i+1);
            }
            else if(s[i]!=x and i==n-1){
                cntl++;
                non.push_back(i+1);
            }
            if(s[i]==x){
                mex=i+1;
            }
        }
        int no=0;
        if(cnt==0 and cntl==0){
            cout<<0<<endl;
        }
        else if(cnt>0 and cntl==0){
            cout<<1<<endl<<n<<endl;
        }
        else if(cnt==0 and cntl>0){
            cout<<1<<endl<<n-1<<endl;
        }
        else if(mex==0){
            cout<<2<<endl<<n<<" "<<n-1<<endl;
        }
        else if(cntl>0 and cnt>0){
            for(int i=0;i<non.size();i++){
                if(non[i]%mex!=0){
                    continue;
                }
                else if(non[i]%mex==0){
                    no++;
                    break;
                }
                
            }
            if(no>0){
                cout<<2<<endl<<n<<" "<<n-1<<endl;
            }
            else cout<<1<<endl<<mex<<endl;
        }
    }
    return 0;
    }