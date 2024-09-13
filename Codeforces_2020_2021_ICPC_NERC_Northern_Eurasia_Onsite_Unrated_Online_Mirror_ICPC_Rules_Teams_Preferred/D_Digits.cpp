




















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

const int maxn = 1e5+3;

int main() {
    fastio;
    int n, d;
    cin >> n >> d;
    vector <int> v(n);
    int cifra = 1;
    for (int i = 0; i < n; i++) cin >> v[i];
    int dp[maxn][11]{};
    for (int i = 0; i < n; i++) {
        int j = v[i]%10;
        cifra = (cifra * j) % 10;
        dp[i][j] = v[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = dp[i-1][j];
        }
        
        int d = v[i]%10;
        if (dp[i][d] != 0) dp[i][d] = min(v[i], dp[i-1][d]);
        else dp[i][d] = v[i];
        
        for (int j = 0; j < 10; j++) {
            if (dp[i-1][j] == 0) continue;
            int dig = (dp[i-1][j] * v[i]) % 10;
            if (dp[i][dig] == 0) dp[i][dig] = dp[i-1][j] * v[i];
            else dp[i][dig] = min(dp[i-1][j] * v[i], dp[i][dig]);
        }
    }
    dbg(cifra);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <10; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
