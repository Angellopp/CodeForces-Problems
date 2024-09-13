#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve() {
    string s;
    cin >> s;
    vector <int> z = z_function(s);
    int xam = -1;
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if(z[i] > xam and i + z[i] == (int)s.size()) {
            j = i;
            xam = z[i];
        }
    }
    int n = s.size();
    if(xam > n / 2) {
        cout << "YES" << endl;
        for (int i = j; i < s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
    }
    else cout << "NO" << endl;
}

int main() {
    fast_io;
    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}