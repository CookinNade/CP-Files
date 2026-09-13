#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,cnt,k; 
    cin>>t;
    while (t--){
        int x1,x2;
        int y1,y2;
        cin>>x1>>x2>>y1>>y2;
        string a = to_string(x1);
        string b = to_string(y1);
        int sza = a.size();
        int szb = b.size();
        if(sza + x2 > szb + y2)cout<<">\n";
        else if(sza + x2 < szb + y2)cout<<"<\n";
        else if(x1>y1)cout<<">\n";
        else if(x1<y1)cout<<"<\n";
        else cout<<"=\n";

    }
    return 0;
    }