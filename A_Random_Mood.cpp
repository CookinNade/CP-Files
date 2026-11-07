#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
double m[2][2]; 
double ans[2][2];
void power(){
    double new_m [2][2];
    for(int i=0;i<2;i++)for(int j=0;j<2;j++) new_m[i][j] = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                new_m[i][k] = new_m[i][k] + m[i][j] * m[j][k];
            }
        }
    }
    for(int i=0;i<2;i++)for(int j=0;j<2;j++) m[i][j] = new_m[i][j];
    return;
}
double mexpo(int n){
    double h = 1;
    double s = 0;
    // for(int i=0;i<2;i++)for(int j=0;j<2;j++) cout<<m[i][j]<<" ";
    while(n>0){
        if(n%2){
            // cout<<h<<" "<<s<<endl;
            double new_h = h * m[0][0] + s * m[1][0];
            double new_s = s * m[1][1] + h * m[0][1];
            h = new_h;
            s = new_s;
            // cout<<h<<" "<<s<<endl;
        }
        power();
        n >>= 1;
    }
    return h;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(10);
    double p;
    int n;
    cin>>n>>p;
    m[0][0] = 1-p; m[1][1] = 1-p;
    m[1][0] = p; m[0][1] = p;
    cout<<mexpo(n);
    
    return 0;
    }