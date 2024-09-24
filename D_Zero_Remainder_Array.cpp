#include <bits/stdc++.h>
#define dd(x) cerr << #x << "= " << x << "." << endl;
using namespace std;
// #define dd(x) cerr << #x << "=  " << x << ".\n"; 


void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    map<int,int> mp;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        v[i] = (v[i] + k - 1) / k * k - v[i];
        mp[v[i]]++;
    }
    int xd = 0, idx = 0;
    for (auto& x : mp) {
        if(x.first != 0 and x.second >= xd) {xd = x.second, idx = x.first;}
    }
    cout << ((xd > 0) ? 1ll * (xd-1) * k + idx + 1 : 0) << endl;
}


int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}