#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n+1), dp(n+1, 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 2*i; j <= n; j+=i) {
            if (v[i] < v[j]) dp[j] = max(dp[j], dp[i]+1);
        }
    }
    int ans = 0;
    for (auto& x : dp) ans = max(ans, x);
    cout << ans << endl;
}


int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();

    }
}