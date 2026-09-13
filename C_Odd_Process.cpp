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
        cin>>n;
        vector<ll>odd; vector<ll>even;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a%2)odd.push_back(a);
            else even.push_back(a);
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        if(odd.empty()){
            for(int i=0;i<n;i++)cout<<0<<" ";
            cout<<endl;
        }
        else if(even.empty()){
            for(int i=0;i<n;i++){
                if(i%2)cout<<0<<" ";
                else cout<<odd[odd.size()-1]<<" ";
            }
            cout<<endl;
        }
        else{
            vector<ll>ans;
            ans.push_back(odd[odd.size()-1]);
            for(int i=even.size()-1;i>=0;i--)ans.push_back(ans[ans.size()-1]+even[i]);
            ll sum=accumulate(even.begin(),even.end(),0ll) + accumulate(odd.begin(),odd.end(),0ll);
            int sz=ans.size();
            for(int i=0;i<n-sz;i++){
                if(n-1==ans.size()){
                    if(sum%2)ans.push_back(ans[ans.size()-2]);
                    else ans.push_back(0);
                    break;
                }
                ans.push_back(ans[ans.size()-2]);
                }
            for(auto x:ans){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
    }