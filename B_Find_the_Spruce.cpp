#include <bits/stdc++.h>
#define dd(x) cerr << #x << "= " << x << "." << endl;
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int j = 0; j < m; j++) {
        if(v[n-1][j] == '*') dp[n-1][j] = 1;
    }
    for (int i = 0; i < n; i++) {
        if(v[i][0] == '*') dp[i][0] = 1;  
        if(v[i][m-1] == '*') dp[i][m-1] = 1;  
    }
    for (int i = n-2; i >= 0; i--) {
        for (int j = 1; j+1 < m; j++) {
            if(v[i][j] == '.') continue;
                dp[i][j] = 1+ min(min(dp[i+1][j-1], dp[i+1][j]), dp[i+1][j+1]);
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += dp[i][j];
        }
    }
    cout << ans << endl;
}


int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}