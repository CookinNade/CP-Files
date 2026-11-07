
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void yo(int m){
    if(m == n+1)return;
    for(int i=0;i<m;i++)cout<<'#';
    cout<<' ';
    yo(m+1);
}
int main() {
    cin>>n;
    yo(1);
    // cout<<'\n';
}