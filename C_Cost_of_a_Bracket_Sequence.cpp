#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    string ss;
    while (t--){

        cin>>n>>k>>ss;
        string ans = ss;
        int cntans = INT_MAX;

        for(int i=0;i<=k;i++){
            int cntl = i;
            int cntr = k - i;

            int l = cntl;
            int r = cntr;
            string s = ss;
            for(int i=0; i<n; i++){
                if(s[i] == '(' and l){
                    s[i] = '-';
                    l--;
                }
            }
            for(int i=n-1; i>=0; i--){
                if(s[i] == ')' and r){
                    s[i] = '-';
                    r--;
                }
            }

            cnt = 0;

            for(int i=0;i<n;i++){
                if(s[i] == '-')continue;
                if(s[i] == '(') l++;
                else{
                    if(l>0){
                        l--;
                        cnt++;
                    }
                }
            }  
            if(cntans > cnt){
                ans = s;
                cntans = cnt;
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i] == '-')cout<<1;
            else cout<<0;
        }
        cout<<'\n';
        
    }
    return 0;
    }