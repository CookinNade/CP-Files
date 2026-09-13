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
        cin>>n>>l>>r;
        vector<ll>va;
        vector<ll>vb;
        for(int i=0;i<n;i++){
            cin>>a;
            if(i>=l and i<r)vb.push_back(a);
            else va.push_back(a);
        }
        ll mn=n+5;
        if(vb.size()){
            mn=*min_element(vb.begin(),vb.end());
        }
        vector<ll>vc;
        for(int i=0;i<vb.size();i++){
            if(vb[i]==mn){
                for(int j=i;j<vb.size();j++)vc.push_back(vb[j]);
                for(int j=0;j<i;j++)vc.push_back(vb[j]);
                break;
            }
        }
        vector<ll>v;
        for(int i=0;i<va.size();i++){
            if(va[i]<mn){
                v.push_back(va[i]);
            }
            else{
                for(auto y:vc){
                    v.push_back(y);
                    // cout<<y<<" ";
                }
                for(int j=i;j<va.size();j++)v.push_back(va[j]);
                break;
            }
        }
        if(v.size()<n)for(auto y:vc)v.push_back(y);
        for(auto y:v)cout<<y<<" ";
        cout<<endl;
    }
    return 0;
    }