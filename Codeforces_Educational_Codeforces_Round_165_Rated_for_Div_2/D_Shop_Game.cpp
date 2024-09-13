#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

int dp[300000+5][10+1][2]{};

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector <int> a(n), b(n);
        vector <pair<int, int>> v(n);
        readv(a, n);
        readv(b, n);
        for (int i = 0; i < n; i++) {
            v.emplace_back(b[i] - a[i], -a[i]);
        }
        sort(v.begin(), v.end());
        

    }
    return 0;
}