#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, k;
    string s;
    cin>>n>>k>>m>>s;
    vector<pair<int,int>>v(m);
    for(int i=0; i<m; i++){
        cin>>v[i].first>>v[i].second;
    }
    set<pair<int,int>>st;
    pair<int,int> current = {1,1};
    int len = 1;
    vector<pair<int,int>>body;
    st.insert(current);
    body.push_back(current);
    // cout<<body[(int)body.size() - len].first<<" "<<body[(int)body.size() - len].second<<endl;
    for(int i=0; i<k; i++){ 
        if(s[i]=='L') current.second = current.second - 1;
        if(s[i]=='R') current.second = current.second + 1;
        if(s[i]=='U') current.first = current.first - 1;
        if(s[i]=='D') current.first = current.first + 1;
        if(current.second == 0) current.second = n;
        if(current.second == n+1) current.second = 1;
        if(current.first == 0) current.first = n;
        if(current.first == n+1) current.first = 1;
        // cout<<current.first<<" "<<current.second<<" "<<len<<endl;
        body.push_back(current);
        if(v[len - 1] == current){
            len++;
            st.insert(current);
        }
        else{
            // cout<<i<<" i and len "<<len<<" "<<body.size()<<endl;
            // cout<<body[(int)body.size() - len].first<<" "<<body[(int)body.size() - len].second<<endl;
            st.erase(body[(int)body.size() - len - 1]);
            if(st.find(current) == st.end()){
                st.insert(current);
                continue;
            }
            else {

                // cout<<"died in "<<i<<" "<<current.first<<" "<<current.second<<" \n";
                cout<<"DEAD";
                return 0;
            }
        }
    }
    cout<<"ALIVE "<<len;
    return 0;
    }