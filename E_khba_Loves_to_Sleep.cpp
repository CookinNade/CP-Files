#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n>>k>>x;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        priority_queue<pair<ll,pair<ll,ll>>>pq;
        set<ll>st; vector<ll>v;
        sort(arr,arr+n);
        pq.push({arr[0],{0,arr[0]}});
        pq.push({x-arr[n-1],{arr[n-1],x}});
        for(int i=1;i<n;i++){
            pq.push({(arr[i]-arr[i-1])/2,{arr[i-1],arr[i]}});
        }
        c=0;
        for(int i=0;i<k;i++){
            d=pq.top().first;
            if(d==0)break;
            r=pq.top().second.second;
            l=pq.top().second.first;
            // cout<<d<<" "<<l<<" "<<r<<endl;
            if(l==0){
                if(arr[0]==0 and n!=1){
                    // cout<<"hello\n";
                    if(r-d==l+d)v.push_back(r-d);
                    else{
                        v.push_back(r-d);
                        v.push_back(l+d);
                    }
                    d--;
                    if(d>=0)pq.push({d,{l,r}});
                }
                else if(arr[0]==0 and n==1){
                    v.push_back(x);
                    x--;
                    if(x>=0)
                    pq.push({x,{0,0}});
                }
                else{
                    v.push_back(r-d);
                    d--;
                    if(d>=0)pq.push({d,{l,r}});
                }
                pq.pop();
                continue;
            }
            else if(r==x){
                if(arr[n-1]==x and n!=1){
                    if(r-d==l+d)v.push_back(r-d);
                    else{
                        v.push_back(r-d);
                        v.push_back(l+d);
                    }
                    d--;
                    if(d>=0)pq.push({d,{l,r}});
                }
                else if(arr[n-1]==x and n==1){
                    v.push_back(c);
                    c++;
                    if(x-c>=0) pq.push({c,{x,x}});      
                }
                else{
                    v.push_back(l+d);
                    d--;
                    if(d>=0)pq.push({d,{l,r}});
                }
                pq.pop();
                continue;
            }
            else if(r-d==l+d)v.push_back(r-d);  
            else{
                v.push_back(r-d);
                v.push_back(l+d);
            }
            d--;
            pq.pop(); 
            if(d>=0)pq.push({d,{l,r}});
        }
        // cout<<"hello\n";
        if(v.size()<k){
            int sz=v.size();
            l=0; sort(v.begin(),v.end());
            for(int i=0;i<k-sz;i++){
                for(;;l++){
                    auto it =st.lower_bound(l);
                    auto nit = lower_bound(v.begin(),v.end(),l);
                    if(nit!= v.end() and (*nit)==l)continue;
                    else if(it!=st.end() and (*it)==l)continue;
                    else {
                        // v.push_back(l);
                        st.insert(l);
                        break;
                    }
                }
            }
        }
        // cout<<v.size()<<endl;
        for(int i=0;i<v.size() and i<k;i++)cout<<v[i]<<" ";
        // cout<<"thgis is set size "<<st.size()<<endl;
        if(v.size()<k){
            int i=0;
            int sz=v.size();
            for(auto it=st.begin();i<k-sz and it!=st.end() ;i++,++it){
                cout<<(*it)<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
    }