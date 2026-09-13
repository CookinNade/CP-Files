#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,d,cnt,l; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>s;
        ll f[26];
        fill(f,f+26,0);
        for(int i=0;i<n;i++)f[s[i]-'a']++;
        vector<int>v;
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(i<=26)v.push_back(n/i);
                if(n/i <=26)v.push_back(i);
            }
        }
        vector<pair<int,int>>c;
        for(int i=0;i<26;i++){
            c.push_back({f[i],i});
        }
        // for(auto x:v)cout<<x<<" ";
        ll final[26];
        fill(final,final+26,0);
        sort(c.rbegin(),c.rend());
        // string ans=s;
        for(int i=0;i<v.size();i++){
            a=v[i];
            l=0;
            ll inc=0;
            ll dec=0;
            int j=0;
            int r=0;
            for(;j<26;j++){
                if(l<n){
                    if(c[j].first>a)dec=dec+c[j].first-a;
                    if(c[j].first<a)inc=inc-c[j].first+a;
                    // cnt=cnt+abs(c[j].first-a);
                    // cout<<cnt<<" "<<c[j].first<<" "<<a<<endl;
                    l=l+a;
                    r=j;
                }
                else{
                    dec=dec+c[j].first;
                }
            }
            // cout<<inc<<" "<<dec<<endl;
            cnt=max(inc,dec);
            // cout<<cnt<<" "<<a<<" "<<j<<endl;
            if(ans>cnt){
                ans=cnt;
                
                for(int k=0;k<=r;k++)final[c[k].second]=a;
                for(int k=r+1;k<26;k++)final[c[k].second]=0;
            }
        }
        cout<<ans<<'\n';
        for(int i=0;i<26;i++){
            a=c[i].first;
            b=final[c[i].second];
            // cout<<a<<" "<<b<<" "<<c[i].second<<endl;
            if(a<=b)continue;
            char x='a'+c[i].second;
            cnt=0;
            for(int j=0;j<n;j++){
                if(cnt < a-b and s[j]==x){
                    s[j]='@';
                    cnt++;
                }
            }
        }
        for(int i=0;i<26;i++){
            a=c[i].first;
            b=final[c[i].second];
            if(a>=b)continue;
            char x='a'+c[i].second;
            cnt=0;
            for(int j=0;j<n;j++){
                if(cnt < b-a and s[j]=='@'){
                    s[j]=x;
                    cnt++;
                }
            }
        }
        cout<<s<<'\n';

    }
    return 0;
    }