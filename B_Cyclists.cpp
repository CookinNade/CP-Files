#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,k,p; 
    cin>>t;
    string s;
    while (t--){
        cnt=0;
        cin>>n>>k>>p>>m;
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        p--;
        while(m>0){
            // cout<<p<<" "<<v[p]<<" "<<k<<" "<<m<<endl;
            if(p<k){
                
                if(m>=v[p])m=m-v[p];
                else break;
                v.push_back(v[p]);
                v.erase(v.begin()+p);
                p=n-1; cnt++; 
                continue;
            }
            ll mn=5002;
            int ind=0;
            for(int i=0;i<k;i++){
                if(mn>v[i]){
                    ind=i;
                    mn=v[ind];
                }
            }
            if(m>=v[ind])m=m-v[ind];
            else break;
            // cout<<m<<" "<<v[ind]<<endl;
            v.push_back(v[ind]);
            v.erase(v.begin()+ind);
            p--;
            // if(o<=2){
            //     cout<<m<<" "<<mn<<" "<<p<<endl;
            // }
            // else break;
        }
        cout<<cnt<<endl;
    }
    return 0;
    }