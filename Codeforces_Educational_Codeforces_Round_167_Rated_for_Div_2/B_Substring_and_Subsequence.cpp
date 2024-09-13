#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int mod = 1e8;

int lcs(string X, string Y, int m, int n, vector<vector<int> >& dp){
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);

    if (dp[m][n] != -1) {
        return dp[m][n];
    }
    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp), lcs(X, Y, m - 1, n, dp));
}

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) {
        string a,  b;
        cin >> a >> b;
        int sa = a.size(), sb = b.size();
        int ans = 1e9;
        for(int i = 0; i < sb; i++) {
            int ax = i;
            for(int j = 0; j < sa; j++) {
                if(ax < sb and a[j] == b[ax]) ax++;
            }
            ans = min(ans, sa + sb - ax + i);
        }
        cout << ans << endl;
    }
}