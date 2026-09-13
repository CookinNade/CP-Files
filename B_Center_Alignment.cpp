#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
void GG(){
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,l;
    cin>>n;
    string arr[n];
    l=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        int sz=arr[i].size();
        l=max(l,sz);
    }
    for(int i=0;i<n;i++){
        int d=l-arr[i].size();
        d=d/2;
        for(int j=0;j<d;j++){
            cout<<'.';
        }
        cout<<arr[i];
        for(int j=0;j<d;j++){
            cout<<'.';
        }
        cout<<endl;
    }
    return 0;
    }