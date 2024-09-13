#include <bits/stdc++.h>
using namespace std;
int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector <int> v(n);
        set <int> sum;
        for (int i = 0; i < n; i++) {cin >> v[i]; v[i] = abs(v[i]);}
        for (int i = 0; i < (1<<n); i++) {
            int ans = 0;
            for (int j = 0; j < n; j++) ans += ((i>>j) & 1) * v[j];
            sum.insert(ans);
        }
        bool can = (sum.size() < (1<<n));
        cout << (can ? "YES" : "NO") << "\n";

    }
}