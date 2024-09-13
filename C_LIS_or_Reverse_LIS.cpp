#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl '\n';
#define dd(x) cerr << #x << "=" << x << "." << endl;
using namespace std;

int n, aux;

void solve() {
    cin >> n;
    vector <int> v(n);
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        mp[aux]++;
    }
    int s = 0;
    for (auto& x : mp) if(x.second == 1) s++;
    cout << (mp.size()-s) + (s+1)/2 << endl;
    
    // sort(all(v));




}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}