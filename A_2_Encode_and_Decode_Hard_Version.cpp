#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    if(s[0] == 'f'){
        // -
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        string ans = "";
        for(int i=0;i<n;i++){
            string d = to_string(arr[i]);
            // string e9 = "xy";
            if(arr[i] == 1e9){
                ans.push_back('x');
            }
            else{
                for(int j=0; j<(int)d.size(); j++)ans.push_back(d[j] - '0' + 'a');
                ans.push_back('y');
            }
        }
        cout<<ans<<endl;
    }
    else{
        string ans;
        cin>>ans;
        // cout<<ans<<endl;
        int n = (int)ans.size();
        string d = "";
        vector<ll>v;
        for(int i=0;i<n;i++){
            if(ans[i] == 'y'){
                ll num = stoll(d);
                v.push_back(num);
                d = "";
            }
            else{
                if(ans[i]=='x'){
                    v.push_back(1e9);
                    d="";
                    continue;
                }
                else {
                    char c = ans[i] - 'a' + '0';
                    d.push_back(c);
                }
            }
        }
        cout<<(int)v.size()<<endl;
        for(auto x:v)cout<<x<<" ";
        // int num = 1e9;
        // cout<<num<<endl;
    }
    return 0;
    }