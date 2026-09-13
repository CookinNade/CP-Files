#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    cin.ignore();
    while (t--){
        string s;
        getline(cin,s);
        size_t ind1 = s.find(" ektu ");
        size_t ind2 = s.find(" jodi ");
        string ektu = "ektu ";
        string jodi = "jodi ";
        bool yes = true;
        // cout<<s<<endl;
        for(int i=0;i<min((int) s.size(), 5);i++){
            if(ektu[i]==s[i]){
                if(i == 4)yes = false;
            }
            else break;
        }
        for(int i=0;i<min((int) s.size(), 5);i++){
            if(jodi[i]==s[i]){
                if(i == 4)yes = false;
            }
            else break;
        }
        int n = (int)s.size();
        ektu = " ektu";
        jodi = " jodi";
        int j = 4;
        for(int i = n-1; i>= max(n-5,0); i--, j--){
            if(ektu[j]==s[i]){
                if(j == 0)yes = false;
            }
            else break;
        }
        j=4;
        for(int i = n-1; i>= max(n-5,0); i--,j--){
            if(jodi[j]==s[i]){
                if(j == 0)yes = false;
            }
            else break;
        }
        if(yes and ind1 == string::npos and ind2 == string::npos and s!= "ektu" and s!="jodi"){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
        
    }
    return 0;
    }