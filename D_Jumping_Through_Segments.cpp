#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t,n,m,a,b,c,d,cnt,k,x; 
    cin>>t;
    string s;
    while (t--){
        cin>>n;
        ll l[n]; ll r[n];
        for(int i=0;i<n;i++){
            cin>>l[i]>>r[i];           
        }
        ll lo=0; ll hi =1e9+10; ll mid;
        while(hi-lo>1){
            ll lowest=0; ll highest=0; int noer=0;
            mid=(hi+lo)/2;
            for(int i=0;i<n;i++){
                if(highest<=l[i]){
                    lowest=highest;
                    if(highest+mid<l[i]){
                        noer++;break;
                    }
                    else if(highest+mid>=r[i]) highest=r[i];
                    else highest = highest+mid;
                    if(lowest+mid>=l[i]) lowest=l[i];
                }
                else if(lowest>=r[i]){
                    highest=lowest;
                    if(lowest-mid>r[i]){
                        noer++; break;
                    }
                    else if(lowest-mid<=l[i])lowest=l[i];
                    else lowest = lowest-mid;
                    if(highest-mid<=r[i])highest=r[i];
                }
                else if(l[i]<=highest and highest<=r[i] and l[i]<=lowest and lowest<=r[i]){
                    if(highest+mid>=r[i]) highest=r[i];
                    else highest=highest+mid;
                    if(lowest-mid<=l[i])lowest=l[i];
                    else lowest=lowest-mid;
                }
                else if(l[i]<=highest and highest<=r[i]){
                    lowest=l[i];
                    if(highest+mid>=r[i]) highest=r[i];
                    else highest=highest+mid;
                }
                else if(l[i]<=lowest and lowest<=r[i]){
                    highest=r[i];
                    if(lowest-mid<=l[i])lowest=l[i];
                    else lowest=lowest-mid;
                }
                else if(l[i]>=lowest and r[i]<=highest){
                    highest=r[i] ; lowest = l[i];
                }
            }
            if(noer) lo=mid+1;
            else hi=mid;
        }
        mid=lo;
        ll highest=0; ll lowest=0; int noer=0;
        for(int i=0;i<n;i++){
                if(highest<=l[i]){
                    lowest=highest;
                    if(highest+mid<l[i]){
                        noer++;break;
                    }
                    else if(highest+mid>=r[i]) highest=r[i];
                    else highest = highest+mid;
                    if(lowest+mid>=l[i]) lowest=l[i];
                }
                else if(lowest>=r[i]){
                    highest=lowest;
                    if(lowest-mid>r[i]){
                        noer++;break;
                    }
                    else if(lowest-mid<=l[i])lowest=l[i];
                    else lowest = lowest-mid;
                    if(highest-mid<=r[i])highest=r[i];
                }
                else if(l[i]<=highest and highest<=r[i] and l[i]<=lowest and lowest<=r[i]){
                    if(highest+mid>=r[i]) highest=r[i];
                    else highest=highest+mid;
                    if(lowest-mid<=l[i])lowest=l[i];
                    else lowest=lowest-mid;
                }
                else if(l[i]<=highest and highest<=r[i]){
                    lowest=l[i];
                    if(highest+mid>=r[i]) highest=r[i];
                    else highest=highest+mid;
                }
                else if(l[i]<=lowest and lowest<=r[i]){
                    highest=r[i];
                    if(lowest-mid<=l[i])lowest=l[i];
                    else lowest=lowest-mid;
                }
                else if(l[i]>=lowest and r[i]<=highest){
                    highest=r[i] ; lowest = l[i];
                }
            }
            if(noer)cout<<hi<<endl;
            else cout<<lo<<endl;
        }
    return 0;
    }