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
        set<int>st;
        cin>>n>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='1')st.insert(i);
        }
        auto it = st.begin();
        a=(*it);
        if(st.size()==0){
            st.insert(1);
            s[1]='1';
        }
        else if(a>=4){
            st.insert(1);
            s[1]='1';
        }
        else if(a==3 or a==2){
            st.insert(0);
            s[0]='1';
        }
        // cout<<s<<endl;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                // cout<<i<<" yo"<<endl;
                auto it = st.upper_bound(i);
                if(it==st.end()){
                    if(n-(i+1)==2){
                        st.insert(i+2);
                        s[i+2]='1';
                    }
                    else if(n-(i+1)>2){
                        st.insert(i+3);
                        s[i+3]='1';
                    }
                }
                else if((*it)-i<=2)continue;
                else if((*it)-i==4){
                    st.insert(i+2);
                    s[i+2]='1';
                }
                else{
                    st.insert(i+3);
                    s[i+3]='1';
                }
            }
        }
        // for(auto it = st.begin();it!=st.end();++it){
        //     cout<<(*it)<<" ";
        // }cout<<endl;
        cout<<st.size()<<endl;
    }
    return 0;
    }