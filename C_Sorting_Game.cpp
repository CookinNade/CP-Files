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
        cin>>n>>s;
        bool pore = is_sorted(s.begin(),s.end());
        if(pore)cout<<"Bob\n";
        else{
            l=0;r=n-1;
            set<ll>st;
            int noer=0;
            for(;l<n;l++){
                if(s[l]=='1'){
                    for(;r>l;r--){
                        if(s[r]=='0'){
                            st.insert(l+1);
                            st.insert(r+1);
                            r--;
                            break;
                        }
                        if(r==l+1){
                            noer++;
                            break;
                        }
                    }
                }
                if(noer)break;
            }
            cout<<"Alice"<<endl;
            cout<<st.size()<<endl;
            for(auto it=st.begin();it!=st.end();++it){
                cout<<(*it)<<" ";
            }cout<<endl;
        }
        
    }
    return 0;
    }