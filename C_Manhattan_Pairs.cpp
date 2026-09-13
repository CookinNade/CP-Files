#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n; cin >> n;
    
    vector <pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        cin >> b[i].first;
        a[i].second = i;
        b[i].second = i;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector <int> c(n), d(n);
    for (int i = 0; i < n; i++){
        c[a[i].second] = i;
        d[b[i].second] = i;
    }
    
    vector <int> t1, t2, t3, t4;
    for (int i = 0; i < n; i++){
        if (c[i] < (n / 2) && d[i] < (n / 2)){
            t1.push_back(i);
        } else if (c[i] >= (n / 2) && d[i] < (n / 2)){
            t2.push_back(i);
        } else if (c[i] >= (n / 2) && d[i] >= (n / 2)){
            t3.push_back(i);
        } else {
            t4.push_back(i);
        }
    }
    
    vector <pair<int, int>> ans;
    for (int i = 0; i < t1.size(); i++){
        ans.push_back({t1[i], t3[i]});
    }
    for (int i = 0; i < t2.size(); i++){
        ans.push_back({t2[i], t4[i]});
    }
    
    for (auto [x, y] : ans){
        cout << (x + 1) << " " << (y + 1) << "\n";
    }
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}