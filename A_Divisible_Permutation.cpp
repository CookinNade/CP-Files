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
        int even = (n-1)%2;
        int first=1;
        int last=n;
        ll arr[n];
        for(int i=n-1;i>=0;i--){
            if(even==i%2){
                arr[i]=first;
                first++;
            }
            else {
                arr[i]=last;
                last--;
            }
        }
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<endl;
    }

    return 0;
    }