#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll w,n,m,a,b,c,d,cnt,r,l,k,x; 
    cin>>w;
    cin>>n;
    ll arr[n];
    ll freq[n];
    fill(freq,freq+n,0ll);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>a;
    while(a--){
        cin>>d;
        if(freq[d-1]%2==0){
            freq[d-1]++;
            w=w+arr[d-1];
            cout<<w<<endl;
        }
        else{
            w=w-arr[d-1];
            cout<<w<<endl;
            freq[d-1]++;
        }
    }
    return 0;
    }