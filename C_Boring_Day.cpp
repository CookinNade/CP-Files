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
        cin>>n>>a>>b;
        ll arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        l=0;r=0; ll sum=0; cnt=0;
        for(;r<n;){

            sum=sum+arr[r];
            // cout<<sum<<" "<<l<<" "<<r<<endl;
            if(a<=sum and sum<=b){
                cnt++;
                // cout<<"it happened "<<cnt<<" "<<sum<<" "<<l<<" "<<r<<endl;
                r++;
                l=r;
                sum=0;
            }
            else if(sum>b){
                if(arr[r]>b){
                    r++;
                    l=r; sum=0;
                }
                else{
                    for(;l<r;){
                        sum=sum-arr[l];
                        if(a<=sum and sum<=b){
                            cnt++;
                            // cout<<"it happened "<<cnt<<" "<<sum<<" "<<l<<" "<<r<<endl;
                            r++;
                            l=r;
                            sum=0; break;
                        } 
                        else if(sum<a){
                            r++; l++;
                            break;
                        }
                        else l++;
                        // cout<<sum<<" "<<l<<" "<<r<<endl; 
                    }
                }
            }
            else r++;
        }
        cout<<cnt<<endl;
    }
    return 0;
    }