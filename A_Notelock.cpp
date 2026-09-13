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
        cin>>n>>k>>s;
        cnt=0;
        set<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='1')st.insert(i);
        }
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                auto it = st.lower_bound(i);
                auto nit = st.begin();
                if(*it==*nit){
                    cnt++; continue;
                }
                it--;
                // cout<<*it<<" "<<i<<endl;
                if(i-*it<k)continue;
                else cnt++;

            }
        }
        cout<<cnt<<endl;
    }
    return 0;
    }