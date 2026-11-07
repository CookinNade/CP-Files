#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int x,y,z;
        cin>>x>>y>>z;
        if(x>=y and x>=z){
            for(int i=0;i<x+y+z;i++)cout<<'P';
        }
        else if(y>=x and y>=z){
            for(int i=0;i<x+y+z;i++)cout<<'R';
        }
        else {
            for(int i=0;i<x+y+z;i++)cout<<'S';
        }
        cout<<'\n';
    }
    return 0;
    }