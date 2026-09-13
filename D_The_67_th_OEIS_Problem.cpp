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
    const ll N=1e4;
    ll siv[N];
    fill(siv,siv+N,0);
    vector<ll>v;
    for(int i=2;i<N;i++){
        if(siv[i])continue;
        else{
            v.push_back(i);
            for(int j=i;j<N;j=j+i){
                siv[j]++;
            }
        }
    }
    // cout<<v.size()<<endl;
    vector<ll>ans;
    for(int i=0;i<v.size()-2;i++){
        for(int j=i+1;j<v.size()-1;j++){
            a=v[i],b=v[j],c=v[j+1];
            ll num=a*b*b;
            ans.push_back(num);
            while(num*c*c<=1e18){
                num=num*a;
                ans.push_back(num);
                if((int)ans.size()>=N)break;
            }
            if(num*c<=1e18)
            ans.push_back(num*c);
            // ans.push_back(c);
            if((int)ans.size()>=N)break;
        }
    }
    // cout<<ans.size()<<endl;
    // set<ll>st;
    // for(int i=0;i<ans.size()-1;i++){
    //     if(st.find(gcd(ans[i],ans[i+1]))==st.end()){
    //         st.insert(gcd(ans[i],ans[i+1]));
    //     }
    //     else{
    //         cout<<gcd(ans[i],ans[i+1])<<endl;
    //         cout<<ans[i]<<" "<<ans[i+1]<<endl;
    //         cout<<i<<" "<<i+1<<endl;
    //     }
    //     if(i==N)break;
    // }
    while (t--){
        cin>>n;
        for(int i=0;i<n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
    }