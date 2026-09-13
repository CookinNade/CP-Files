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
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;;
        }
        int ans=-1;
        
        cout<<s.size()-mp[s[n-1]]<<endl;
    }
    return 0;
    }