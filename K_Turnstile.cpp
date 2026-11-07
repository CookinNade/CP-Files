#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
string s;
void perm(int i){

}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        s = to_string(n);
        // cout<<s<<endl;
        if((int)s.size()>10){
            cout<<-1<<'\n';
            continue;
        }
        int m = (int)s.size();
        set<char>st;
        for(int i=0;i<m;i++)st.insert(s[i]);
        if(st.size() == m){
            cout<<0<<'\n';
            continue;
        }
        bool use[10];
        fill(use,use+10,false);
        string can = "";
        can.push_back('1');
        int k = 0;
        ll ans = LLONG_MAX;
        if(m!=10){
            for(int i=0;i<(int)s.size();i++){
                if(k==1)k++;
                char c = '0' + k;
                can.push_back(c);
                k++;
            }
        }
        
        if(stoll(can) > n)ans = stoll(can) - n;
        
        string pot = "";
        bool check[10];
        for(int i=0;i<m;i++){
            string yes = pot;
            fill(check,check+10,false);
            for(int r=0;r<i;r++){
                check[s[r] - '0'] = true;
            }
            int hobe = -1;
            for(int l=s[i]-'0' + 1;l<=9;l++) if(!check[l]){
                hobe = l;
                check[hobe] = true;
                break;
            }
            if(hobe == -1){
                for(int l=0;l<=9;l++) if(!check[l]){
                    hobe = l;
                    check[hobe] = true;
                    break;
                }
            }
            char c = (char)('0' + hobe);
            yes.push_back(c);
            

            for(int j=i+1;j<m;j++){
                for(int l=0;l<=9;l++) if(!check[l]){
                    hobe = l;
                    check[hobe] = true;
                    break;
                }
                c = (char)('0' + hobe);
                yes.push_back(c);
            }
            st.clear();
            for(int i=0;i<m;i++)st.insert(yes[i]);
            ll num = stoll(yes);
            
            if((int)st.size()==m and num > n) ans = min(ans, num - n);
            pot.push_back(s[i]);
        }
        
        if(ans == LLONG_MAX)cout<<-1<<'\n';
        else cout<<ans<<'\n';
        
        
    }
    return 0;
    }