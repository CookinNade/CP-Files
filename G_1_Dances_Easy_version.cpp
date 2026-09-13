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
        cin>>n;
        int arra[n]; int arrb[n];
        for(int i=0;i<n;i++)cin>>arra[i];
        for(int i=0;i<n;i++)cin>>arrb[i];
        sort(arra,arra+n);sort(arrb,arrb+n); 
        r=n-1; l=0;
        cnt=0;
        for(int i=0;i<n;i++){
            // cout<<arrb[i]<<" "<<arra[l]<<" ";
            if(arrb[i]>arra[l]){
                l++;
                // cout<<"it was bigger\n";
            }
            else{
                // cout<<"it was smaller\n";
                cnt++;
                r--;
            }   
        }
        cout<<cnt<<endl;
    }
    return 0;
    }