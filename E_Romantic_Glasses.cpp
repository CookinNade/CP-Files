#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        unordered_set<ll>st;st.insert(0);
        ll sum=0;int yes=0;
        for(int i=0;i<n;i++){
            cin>>a; 
            if(i%2==1){
                sum = sum-a;
                if(st.find(sum)!=st.end()) yes++;
                st.insert(sum);
                
            }
            else if(i%2==0){
                sum = sum+a;
                if(st.find(sum)!=st.end()) yes++;
                st.insert(sum);
            }
            // cout<<sum<<" ";
        }
        // cout<<endl;
        cout<<(yes>0?"YES\n":"NO\n");

    }
    return 0;
    }