#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll pow(ll a,ll b){
    ll res = 1;
    for(int i=0;i<b;i++){
        res *=a;
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        cout<<"MUL 1"<<endl;
        ll in;
        cin>>in;
        map<ll,ll>mp;
        for(int i=2;i*i<=in;i++){
            if(in%i==0){
                int cnt = 0;
                while(in % i == 0){
                    cnt++;
                    in /= i;
                }
                mp[i] = cnt;  
            }
        }
        if(in > 1)mp[in] = 1;
        ll mul=1;
        for(auto it = mp.begin();it!=mp.end();++it){
            ll a = (*it).first;
            ll b = (*it).second;
            mul = mul * pow(a,b);
        }
        cout<<"MUL "<<mul<<endl;
        cin>>in;
        ll ansa = 1; ll ansb = 1;
        ll notun = 1;
        for(int i=2;i*i<=in;i++){
            if(in % i == 0){
                int cnt = 0;
                while(in % i == 0){
                    cnt++;
                    in /= i;
                }
                ll apow = -mp[i] + cnt;
                notun = notun * pow(i,cnt);
                ansa = ansa * pow(i,apow);
            }
        }
        if(in>1){
            ll apow = -mp[in] + 1;
            ansa = ansa * pow(in,apow);
            notun = notun * in;
        }
        cout<<"DIV "<<notun<<endl;
        cin>>in;
        for(int i=2;i*i<=in;i++){
            if(in % i == 0){
                int cnt = 0;
                while(in % i == 0){
                    cnt++;
                    in /= i;
                }
                ansb = ansb * pow(i , cnt);
            }
        }
        if(in > 1) ansb = ansb * in;
        cout<<"ANS "<<ansa<<" "<<ansb<<endl;
    }
    return 0;
    }