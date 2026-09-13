#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k;
        ll cost =0;
        map <ll,ll>mp;
        ll arr[20];
        ll cs =1;
        for(int i=0;i<19;i++){
            arr[i]= (cs*3)+i*(cs/3);
            cs = cs*3;
        }
        r=0;
        while(n>0){
            ll sum=1; cnt=0;
            while (sum * 3 <= n) {
                sum =sum*3;
                cnt++;
            }
            mp[cnt]++;
            n=n-sum;
            r++;
        }                
        if(r>k) cout<<-1<<endl;
        else{
            l=r;
            for(auto it =--mp.end();l+2<=k;){
                    ll rem = k-l;
                    if((*it).first==0)break;
                    else if(rem>=((*it).second)*2){
                        mp[(*it).first-1]=((*it).second*3)+mp[(*it).first-1];
                        l=l + (*it).second*2;
                        mp[(*it).first]=0;
                        it--;
                    }
                    else if(rem<((*it).second)*2){
                        ll need =rem/2;
                        mp[(*it).first-1]=need*3+mp[(*it).first-1];
                        mp[(*it).first]=mp[(*it).first]-need;
                        break;
                    }
            }
            for(auto it=mp.begin();it!=mp.end();++it) cost = cost + arr[(*it).first]*(mp[(*it).first]);
            cout<<cost<<endl;
        }
    }
    return 0;
    }