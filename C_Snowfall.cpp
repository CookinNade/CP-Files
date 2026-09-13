#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        vector<int>v;
        vector<int>v2;
        vector<int>v3;
        vector<int>v6;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a%6 and a%2 and a%3)v.push_back(a);
            else if(a%2 and a%3==0)v3.push_back(a);
            else if(a%3 and a%2==0)v2.push_back(a);
            else v6.push_back(a);
        }
        for(auto x:v2)cout<<x<<" ";
        for(auto x:v)cout<<x<<" ";
        for(auto x:v3)cout<<x<<" ";
        for(auto x:v6)cout<<x<<" ";
        cout<<endl;
    }
    return 0;
    }