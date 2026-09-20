#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int n;
bool valid(int i, int j){
    // cout<<"check er jonno ashche "<<i<<" "<<j<<" "<<k<<endl;
    if(i>=1 and i<=n and j>=1 and j<=n)return true;
    return false;
}
bool query(int i , int j, int x ,int y){
    if(!valid(i,j))return false;
    cout<<"? "<<min(i,x)<<" "<<min(j,y)<<" "<<max(i,x)<<" "<<max(j,y)<<endl;
    string s;
    cin>>s;
    if(s == "YES")return true;
    return false;
}
int main () {
    cin>>n;
    int dx = n;
    int dy = 1;
    while(true){
        if(query(dx,dy,1,1) and query(dx,dy,n,n))break;
        dx--;
        dy++;
    }
    int cx = n;
    int cy = n;
    string ntheke = "";
    while(cx != dx or cy != dy){
        // cout<<"from "<<cx<<" "<<cy<<" to ";
        if(query(cx,cy-1,1,1)){
            cy--;
            ntheke.push_back('R');
        }
        else {
            cx--;
            ntheke.push_back('D');
        }
        // cout<<cx<<" "<<cy<<" \n";
        // if(cx == dx and cy == dy)
    }
    cx = 1;
    cy = 1;
    string onetheke = "";
    while(cx != dx or cy != dy){
        // cout<<"from "<<cx<<" "<<cy<<" to ";
        if(query(cx+1,cy,n,n)){
            cx++;
            onetheke.push_back('D');
        }
        else {
            cy++;
            onetheke.push_back('R');
        }
        // cout<<cx<<" "<<cy<<" \n";
    }
    reverse(ntheke.begin(),ntheke.end());
    // cout<<onetheke<<" "<<ntheke<<endl;
    cout<<"! "<<onetheke<<ntheke<<endl;
    return 0;
    }