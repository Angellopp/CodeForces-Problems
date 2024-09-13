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
    vector <vector <int>> v(2, vector<int> ((int)2e5+1)); 
    while(t--) {
        int n;
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        int v0 = 0, v1 = 0;
        for (int i = 0; i < n; i++) {
            if(v[0][i] == v[1][i]) continue;
            if(v[0][i] > v[1][i]) v0 += v[0][i];
            else v1 += v[1][i];
        }
        for (int i = 0; i < n; i++) {
            if(v[0][i] != v[1][i]) continue;
            if(v[0][i] >= 0) {
                if(v0 >= v1) v1 += v[0][i];
                else v0 += v[1][i];
            }
            else {
                if(v0 >= v1) v0 += v[0][i];
                else v1 += v[1][i];
            }
        }
        cout << min(v0, v1) << endl;
    }
}