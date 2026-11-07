#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 100;
int g[N][N];
int n;
bool valid(int i, int j){
    if(i>=0 and i<n and j>=0 and j<n)return true;
    return false;
}
void move(int i, int j, int k){
    g[i][j]+=k;
    for(int l=0;l<n;l++)if(l!=j)g[i][l]+=k;
    for(int l=0;l<n;l++)if(l!=i)g[l][j]+=k;
    int r = i, c = j;
    for(;;r++,c--){
        if(r==i and c==j)continue;
        if(!valid(r,c))break;
        g[r][c]+=k;
    }
    r = i, c = j;
    for(;;r++,c++){
        if(r==i and c==j)continue;
        if(!valid(r,c))break;
        g[r][c]+=k;
    }
    r = i, c = j;
    for(;;r--,c--){
        if(r==i and c==j)continue;
        if(!valid(r,c))break;
        g[r][c]+=k;
    }
    r = i, c = j;
    for(;;r--,c++){
        if(r==i and c==j)continue;
        if(!valid(r,c))break;
        g[r][c]+=k;
    }
}
int cnt;
void queen(int i, int k){
    if(k <= 0){
        cnt++;
        return;
    }
    for(int j=0;j<n;j++){
        if(g[i][j] == 0){
            move(i,j,1);
            queen(i+1,k-1);
            move(i,j,-1);
        }
    }
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    queen(0,n);
    cout<<cnt<<'\n';
    
    return 0;
}