#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int a[3]; int da[3];
int b[3]; int db[3];

bool dest1(){
    bool ans = true;
    for(int i=0;i<3;i++) ans &= (a[i] == da[i]);    
    return ans;
}
bool dest2(){
    bool ans = true;
    for(int i=0;i<3;i++) ans &= (b[i] == db[i]);    
    return ans;
}
bool same(){
    bool ans = true;
    for(int i=0;i<3;i++) ans &= (b[i] == a[i]);    
    return ans;
}
void move(int x, int y){
    while(a[x]!= da[x] or b[y]!=db[y]){
        if(da[x] > a[x]) a[x]++;
        if(da[x] < a[x]) a[x]--;
        if(db[y] > b[y]) b[y]++;
        if(db[y] < b[y]) b[y]--;
        if(same()){
            
        }
        cout<<"(";
        for(int i=0;i<3;i++){
            if(i!=2)cout<<a[i]<<" ";
            else cout<<a[i];
        }
        cout<<") ";
        cout<<"(";
        for(int i=0;i<3;i++){
            if(i!=2)cout<<b[i]<<" ";
            else cout<<b[i];
        }
        cout<<")\n";
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<3;i++)cin>>a[i]; for(int i=0;i<3;i++)cin>>da[i];
    for(int i=0;i<3;i++)cin>>b[i]; for(int i=0;i<3;i++)cin>>db[i];
    
    
    return 0;
    }