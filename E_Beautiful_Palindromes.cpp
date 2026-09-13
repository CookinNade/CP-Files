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
        cin>>n>>k;
        set<ll>st;
        ll arr[n];
        for(int i=1;i<=n;i++){
            st.insert(i);
        }
        set<ll>ache;
        vector<ll>v;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            st.erase(arr[i]);
            if(ache.find(arr[i])==ache.end()){
                
                v.push_back(arr[i]);
                ache.insert(arr[i]);
            }
        }
        if(st.size()==0){
            for(int i=0;i<k;i++)cout<<arr[i]<<" ";
            cout<<endl;
        }
        else if(st.size()==1){
            auto it=st.begin();
            cout<<*it<<" "; k--;
            if(arr[n-1]==arr[0]){
                for(int i=0;i<k;i++){
                    cout<<arr[i+1]<<" ";
                }
            }
            else{
                for(int i=0;i<k;i++){
                    cout<<v[i]<<" ";
                }
            }
            cout<<endl;
        }
        else{
            for(auto it =st.begin();it!=st.end();++it){
                k--;
                cout<<*it<<" ";
                if(k==0)break;
            }
            if(k>0){
                for(int i=0;i<k;i++){
                    cout<<v[i]<<" ";
                }
            }cout<<endl;
        }
    }
    return 0;
    }