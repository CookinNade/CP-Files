#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        set<int>st;
        map<ll,ll> freq;
        for(int i=0;i<n;i++){
            cin>>a; st.insert(a);
            freq[a]++;
        }
        k=0;
        
        cnt=0;
        for(;!st.empty();){
            auto it=st.begin();
            int num=*it;
            freq[num]--;
            if(freq[num]==0)st.erase(num);
            for(int j=num+1;;j++){
                // cout<<j<<endl;
                if(freq[j]>0){
                    freq[j]--;
                    if(freq[j]==0)st.erase(j);
                }
                else break;
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
    }