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
        cin>>n>>k;
        int arr[n];
        int sort_arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sort_arr[i]=arr[i];
        }
        if(k>1){
            cout<<"YES\n";
        }
        else {
            bool man = is_sorted(arr,arr+n);
            if(man){
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }
    }
    return 0;
    }