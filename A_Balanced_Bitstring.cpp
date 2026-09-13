#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k>>s;
        int no=0;
        set<char>st;
        bool vis[n];
        fill(vis,vis+n,false);
        int f=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                st.clear();
                for(int j=i;j<n;j=j+k){
                    vis[j]=true;
                    if(s[j]=='?')continue;
                    else st.insert(s[j]);
                }
                // if(i==2){
                //     cout<<st.size()<<endl;
                //     char c = *(st.begin());
                //     cout<<c<<endl;
                // }
                if(st.size()==1){
                    char c = *(st.begin());
                    for(int j=i;j<n;j=j+k){
                        // cout<<j<<endl;
                        s[j]=c;
                    }
                }
                else if(st.size()==0){
                    f++;
                }
                else {
                    no++; break;
                }
            }
        }
        if(no){
            cout<<"NO\n";
            continue;
        }
        cnt=0; int cnt1=0;
        for(int i=0;i<k;i++){
            if(s[i]=='1')cnt1++;
            else if(s[i]=='0')cnt++;
        }
        l=0;r=k-1;
        for(;r<n;){
            if(abs(cnt-cnt1)>f){
                no++; break;
            }
            r++;
            if(r!=n){
                if(s[r]=='1')cnt1++;
                if(s[r]=='0')cnt++;
                if(s[l]=='1')cnt1--;
                if(s[l]=='0')cnt--;
                l++;
            }
        }
        // cout<<s<<endl;
        if(no)cout<<"NO\n";
        else cout<<"YES\n";
        // cout<<s<<endl;
    }
    return 0;
    }