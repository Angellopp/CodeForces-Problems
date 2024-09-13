#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

bool valid(string x) {
    if(x[0] == '0') return 0;
    return 1;
}

int main() {
    fastio;
    string s;
    cin >> s;
    int sz = 1;
    int n = stoi(s);
    // cout << sz << "\n";
    vector <int> v(n+1);
    v[1] = 1;
    v[2] = 2;
    for (int i = 3; i <= n; i++) {
        string ss = to_string(i);
        sz = ss.size();
        int mn = 1e9;
        for (int j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                mn = min(mn, v[i/j] + v[j]);
            }
        }
        for (int j = 1; j <= i/2; j++) {
            mn = min(mn, v[j] + v[i-j]);
        }

        for (int j = 1; j < sz; j++) {
            string x = ss.substr(0, j);
            string y = ss.substr(j, sz-j);
            // cout << "s " << s << " x: " << x << " y: " << y << endl;
            if (valid(x) and valid(y)) {
                mn = min(mn, v[stoi(x)] + v[stoi(y)]);
            }
        }
        v[i] = mn;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << "v[" << i << "] = " << v[i] << " \n";
    // }
    cout << v[n] << "\n";
}