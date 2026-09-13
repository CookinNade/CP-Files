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
        cin>>n;
        
        int freq[n+1]={0};
        int ans[n+1]={0};
        for(int i=1;i<=n;i++){
            cin>>a;
            if(a>n)continue;
            freq[a]++;
            st.insert(a);
        }
        for(auto it=st.begin();it!=st.end();it++)for(int j=(*it);j<=n;j=j+(*it))ans[j]=ans[j]+freq[(*it)];
        sort(ans+1,ans+n+1,greater<int>());
        cout<<ans[1]<<endl;
    }
    return 0;
    }