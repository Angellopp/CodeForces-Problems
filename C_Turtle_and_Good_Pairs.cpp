#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // vector <pair<int, char>> ans;
    // sort(all(s));
    map<char, int> mp;

    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    vector <pair<int, char>> v;
    for (auto x : mp) {
        v.emplace_back(x.S, x.F);
    }
    sort(rall(v));
    for (int i = 0; i < s.size();) {
        for (int j = 0; j < v.size(); j++) {
            if(v[j].F) {
                cout << v[j].S;
                v[j].F--;
                i++;
            }
        }
    }
    cout << endl;
}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}