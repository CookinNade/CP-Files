#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cin>>n;
        vector<ll>v1;
        vector<ll>v2;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(i % 2)v2.push_back(a);
            else v1.push_back(a);
        }
        for(int i=0;i<(int)v1.size();i++)if(v1[i]<0)cnt1++;
        for(int i=0;i<(int)v2.size();i++)if(v2[i]<0)cnt2++;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        if(cnt1>cnt2){
            for(int i=0;i<(int)v2.size();i++)if(v2[i] == 0)cnt2++;
            cnt2 = min(cnt2,cnt1);
            
            for(int i=0;i<(int)v2.size();i++)v2[i] = abs(v2[i]);
            for(int i=0;i<cnt2 and i<v1.size();i++)v1[i] = abs(v1[i]);
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            int r = 0;
            for(int i=0;i<(int)v1.size() and r<(int)v2.size();i++){
                if(v1[i] <0 and abs(v1[i]) > v2[r]){
                    v1[i] = -v1[i];
                    v2[r] = -v2[r];
                    // cout<<i<<" "<<r<<" "<<v1[i]<<" "<<v2[r]<<endl;
                    r++;
                }
                else break;
            }
        }
        else{
            for(int i=0;i<(int)v1.size();i++)if(v1[i] == 0)cnt1++;
            cnt1 = min(cnt2,cnt1);

            for(int i=0;i<(int)v1.size();i++)v1[i] = abs(v1[i]);
            for(int i=0;i<cnt1 and i<(int)v2.size();i++)v2[i] = abs(v2[i]);
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            int r = 0;
            for(int i=0;i<(int)v2.size() and r<(int)v1.size();i++){
                if(v2[i] <0 and abs(v2[i]) > v1[r]){
                    v2[i] = -v2[i];
                    v1[r] = -v1[r];
                    r++;
                }
                else break;
            }
        }
        ll sum = 0;
        for(auto c:v1)sum += c;
        for(auto c:v2)sum += c;
        cout<<sum<<'\n';

    }
    return 0;
    }